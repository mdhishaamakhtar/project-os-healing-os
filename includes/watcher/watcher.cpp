#include <iostream>
#include <vector>
#include <string>

#include "watcher.h"
#include "./../rainbow/rainbow.h"
#include "./../git_actions/git_actions.h"
#include "./../logger/logger.h"
#include "./../time-parser/timeparser.cpp"

using namespace std;

/**
 * Function to split a string
 */
vector<string> split(const string& str, const string& delim) {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

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
    TimeParser parser;
    string cmd = command.at(0) + " " + command.at(1);
    cout << cmd << endl;
    string name = "";
    if (command.size() == 3) {
        name = command.at(2);
    }
    if (cmd == ":checkpoint create") {
        string message = "Created Checkpoint";
        g.add();
        g.commit(message);
    }
    else if (cmd == ":checkpoint revert") {
        g.revert();
    }
    else if (cmd == ":branch new") {
        g.create_branch(name);
    }
    else if (cmd == ":branch accept") {
        g.merge_branch(name);
    }
    else if (cmd == ":branch switch") {
        g.checkout(name);
    }
    else if (cmd == ":branch delete") {
        g.delete_branch(name);
    }
    else if (cmd == ":add remote") {
        g.add_remote(name);
    }
    else if (cmd == ":cloud push") {
        g.push(name);
    }
    else if (cmd == ":cloud pull") {
        g.pull();
    }
    else if (cmd == ":logs show") {
        vector<string> history = logger.readAll();
        for (auto s : history) {
            vector<string> k = split(s, "|");
            if (k.at(1) == "system") {
                cout << parser.parseTime(stoi(k.at(2))) << "\t" << rainbow::italic(rainbow::orange(k.at(1))) << "  \t" << rainbow::italic(rainbow::red(k.at(0))) << endl;
            }
            else {
                cout << parser.parseTime(stoi(k.at(2))) << "\t" << rainbow::italic(rainbow::orange(k.at(1))) << "\t" << rainbow::italic(rainbow::red(k.at(0))) << endl;
            }
        }
    }
}
