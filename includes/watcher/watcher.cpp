#include <iostream>
#include <vector>
#include <string>

#include "watcher.h"
#include "./../rainbow/rainbow.h"
#include "./../git_actions/git_actions.h"
#include "./../logger/logger.cpp"

using namespace std;

// class Watcher {

// public:
//     /**
//      * Vector which stores all commands available for the User
//      * More to be added when core utility is implemented
//      */
//     vector<string> available_commands = {
//         ":checkpoint create",
//         ":checkpoint revert",
//         ":branch new",
//         ":branch switch",
//         ":branch delete",
//         ":branch accept",
//         ":cloud attach",
//         ":cloud pull",
//         ":cloud push",
//         ":logs show",
//         ":logs clean"
//     };

//     /**Function to enter a command */
//     string listenForCommand(string context);

//     /**
//      * Function to call the utility function to
//      * be implemented when the functions are ready
//      */
//     void taskDispatcher(vector<string> command);

//     /** Functon to check if command is allowed or not */
//     bool ifValidInternalCommand(string command);
// };

/** Implementation of enter_command */
string Watcher::listenForCommand(string context) {
    string command = "";
    cout << rainbow::green(rainbow::italic(context)) << " > ";

    while (command == "" || command == " ") {
        getline(cin, command);
    }
    return command;
}

/** Implementation of command checker: Uses Linear Search */
bool Watcher::ifValidInternalCommand(string command) {
    for (auto cmd : Watcher::available_commands) {
        if (cmd == command) {
            return true;
        }
    }
    return false;
}

void Watcher::taskDispatcher(vector<string> command) {
    git_actions g;
    LoggerModule logger;
    string cmd = command.at(0) + command.at(1);
    string name = "";
    if (command.size() == 3) {
        name = command.at(2);
    }
    if (cmd == ":checkpoint create") {
        string message = "Created Checkpoint";
        g.add();
        g.commit(message);
    }
    else if (cmd == ":branch new") {
        g.create_branch(name);
    }
    else if (cmd == ":branch switch") {
        g.checkout(name);
    }
    else if (cmd == ":cloud push") {
        g.push(name);
    }
    else if (cmd == ":cloud pull") {
        g.pull();
    }
    else if (cmd == ":logs show") {
        vector<string> history = logger.readAll();
        for (auto cmnd : history) {
            cout << rainbow::red(rainbow::italic(cmnd)) << endl;
        }
    }
}
