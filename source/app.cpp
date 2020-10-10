#include<iostream>
#include"./../includes/rainbow/rainbow.h"
#include"./../includes/watcher/watcher.h"
#include"./../includes/logger/logger.cpp"
#include <sstream>
#include<string>
using namespace std;
int main(){
    cout << rainbow::underline(rainbow::bold(rainbow::red("SELF HEALING OS"))) << endl << endl; 
    cout << rainbow::bold("Logger Usage") << endl;
    LoggerModule logger;
    logger.save("system", "ls");
    logger.save("system", "mkdir directory");
    logger.save("system", "cat commands.txt");
    logger.save("internal", ":checkpoint create");
    logger.save("internal", ":checkpoint delete");
    Watcher w;
    LoggerClass l;
    while (true) {
        std::string command = w.enter_command();
        l.logInfo(command, "command");
        if (command == "exit") {
            break;
        }
        if (command[0] != ':') {
            std::cout << "Given command is a system command" << std::endl;
            char cmd[command.size() + 1];
            strcpy(cmd, command.c_str());
            system(cmd);
            continue;
        }
        std::string word = "";
        std::vector<string> s;
        std::stringstream iss(command);
        while (iss >> word) {
            s.push_back(word);
        }
        if (s.size() <= 1) {
            std::cout << "Please enter the correct command again" << std::endl;
            continue;
        }
        string command_to_pass = s.at(0) + " " + s.at(1);
        if (!w.command_checker(command_to_pass)) {
            std::cout << "Please enter the correct command again" << std::endl;
            continue;
        }
        std::cout << "Command executed" << std::endl;
        return 0;
    }
    return 0;
}