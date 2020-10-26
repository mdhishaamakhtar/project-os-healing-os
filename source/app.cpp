#include<iostream>
#include <sstream>
#include <string>

#include"./../includes/rainbow/rainbow.h"
#include"./../includes/logger/logger.cpp"
#include"./../includes/watcher/watcher.cpp"
#include"./../includes/log_processor/log_processor.h"

using namespace std;

int main(){
    string username;
    string commandType;

    // showing basic ui to user
    cout << rainbow::underline(rainbow::bold(rainbow::red("SELF HEALING OS"))) << endl << endl;
    cout << rainbow::grey("Welcome, please enter your username : ");
    cin >> username; 

    LoggerModule logger;
    Watcher watcher;
    
    /** start infinite loop to take commands until user quits **/
    cout << rainbow::grey("logging you in, type \"exit\" or  press ") 
            << rainbow::grey(rainbow::bold("CTRL"))
            << "+"
            << rainbow::grey(rainbow::bold("C"))
            << rainbow::grey(" to quit the system.")
            << endl << endl;

    while (true) {
        commandType = "internal";
        string command = watcher.listenForCommand(username);
        
        /** a clean exit **/
        if (command == "exit") {
            break;
        }

        /** handle when internal command entered **/
        if (command[0] != ':') {
            commandType = "system";
            char cmd[command.size() + 1];
            strcpy(cmd, command.c_str());
            logger.save(commandType, cmd);
            system(cmd);
            continue;
        }

        /** handle internal commands **/
        string word = "";
        vector<string> s;
        stringstream iss(command);
        while (iss >> word) {
            s.push_back(word);
        }

        if (s.size() <= 1) {
            cout << rainbow::bold(rainbow::red("Please enter a correct command")) << endl;
            continue;
        }
        string command_to_pass = s.at(0) + " " + s.at(1);
        
        if (!watcher.ifValidInternalCommand(command_to_pass)) {
            cout << rainbow::bold(rainbow::red("Please enter a correct command")) << endl;
            continue;
        }
        logger.save(commandType, word);
        cout << rainbow::italic(rainbow::grey("internal command executed")) << endl;
    }


    // cout << endl << rainbow::bold(rainbow::underline("Reading and Processing Logs")) << endl;
    // vector<string> commands = logger.readAll();

    // cout << rainbow::red("Displaying all entries from timestamp 1602327666") << endl;
    // LogProcessor logProcessor(commands);
    // for(auto entry : logProcessor.Fetch(1602327666)){
    //     cout << entry.timestamp << " : " << entry.command << endl;
    // }


    return 0;
}