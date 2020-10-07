#include <iostream>
#include <fstream>
#inlcude <string>
#include "build/include/cppgit2/repository.hpp"
#include "git_actions.h"
using namespace cppgit2;

class git_actions
{
public:
	
	void create_repo(string input)
	{
		auto repo = repository::init(input, false);
	}

	void clone_repo(string url, string path)
	{
		clone::options options;
		auto repo = repository::clone(url, path, options);
	}

	//the path here points to a git directory
	void add(string path, string file_name)
	{
		auto repo = repository::open(path);
		auto index = repo.index();
	    index.add_entry_by_path(file_name);
	    index.write();
	}

	//commiting with custom message
	auto commit(string path, auto index, string name, string email, string message)
	{
		auto repo = repository::open(path);
		auto tree_oid = index.write_tree();

	    auto author = signature(name, email);
    	auto committer = signature(name, email);

    	auto commit_oid = repo.create_commit("HEAD", author, committer, "utf-8", message, repo.lookup_tree(tree_oid), {});

    	std::cout << "Created commit with ID: " << commit_oid.to_hex_string() << std::endl;

    	return commit_oid;
	}

	//DOUBT ASK VERMS
	auto create_branch(string branch_name, string commit_oid)
	{
		auto commit = repo.lookup_commit(commit_oid);
		auto branch_ref = repo.create_branch(branch_name, commit, false);
		std::cout << "Created branch " << branch_name << std::endl;

		return branch_ref;
	}

	void checkout_branch(auto branch_name, auto branch_ref)
	{
		auto treeish = repo.revparse_to_object(branch_name);
	    repo.checkout_tree(treeish);		
	    repo.set_head(branch_ref.name());

	    std::cout << "Checked out " << branch_name << std::endl;
	}
};