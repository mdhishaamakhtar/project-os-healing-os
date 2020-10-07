#include"watcher.h"
#include <sstream>
// #include"../git_actions/git_actions.cpp" // Creating a compilation error
#include"../logger/logger.cpp"
#include<string>
int main() {
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
    }
}