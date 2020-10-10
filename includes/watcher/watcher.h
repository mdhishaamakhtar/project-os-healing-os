#include <iostream>
#include <vector>
#include <string>

#include"./../rainbow/rainbow.h"

using namespace std;

class Watcher {
public:
    /**
     * Vector which stores all commands available for the User
     * More to be added when core utility is implemented
     */
    vector<string> available_commands = {
        ":checkpoint create",
        ":checkpoint revert",
        ":branch new",
        ":branch switch",
        ":branch delete",
        ":branch accept",
        ":cloud attach",
        ":cloud sync"
    };

    /**Function to enter a command */
    string enter_command(string context);

    /** Function to call the utility function 
     * To be implemented when the functions are ready */
    void call_utility(string command);

    /** Functon to check if command is allowed or not */
    bool command_checker(string command);
};


/** Implementation of enter_command */
string Watcher::enter_command(string context) {
    string command;
    cout << rainbow::italic(context) << " > ";
    getline(cin, command);
    return command;
}

/** Implementation of command checker: Uses Linear Search */
bool Watcher::command_checker(string command) {
    for (auto cmd : Watcher::available_commands) {
        if (cmd == command) {
            return true;
        }
    }
    return false;
}