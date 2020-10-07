#include"watcher.h"
#include"../git_actions/git_actions.h"
#include<string>
int main() {
    Watcher w;
    while (true) {
        std::string command = w.enter_command();
        if (command[0] != ':') {
            std::cout << "Please enter the correct command again" << std::endl;
            continue;
        }
        if (command == "exit") {
            break;
        }
        string word = "";
        vector<string> s;
        for (auto x : command) {
            if (x == ' ') {
                s.push_back(word);
                word = "";
            }
            else {
                word = word + x;
            }
        }
        string command_to_pass = s.at(0) + s.at(1);
        if(!w.command_checker(command_to_pass)){
            std::cout << "Please enter the correct command again" << std::endl;
        }
    }
}