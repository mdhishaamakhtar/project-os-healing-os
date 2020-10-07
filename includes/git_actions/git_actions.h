#ifndef git_actions
#define git_actions
#include <string>
using namespace std;


class git_actions{
    public:
	    static void create_repo(string input);
        static void clone_repo(string url, string path);
        static void add(string path, string file_name);
        static auto commit(string path, string index, string name, string email, string message);
};
#endif