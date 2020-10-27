#ifndef GIT_ACTIONS_H
#define GIT_ACTIONS_H
#include <string>
using namespace std;


class git_actions{
    public:
	    static void create_repo(string input);
        static void clone_repo(string url);
        static void add();
        static void commit(string message);
        static void push(string branchName);
        static void pull();
        static void create_branch(string branchName);
        static void checkout(string branchName);
};
#endif