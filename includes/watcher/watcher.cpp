#include<watcher.h>
#include<string>
int main() {
    Watcher w;
    while (true) {
        std::string command = w.enter_command();
        if (command[0] != ':') {
            std::cout << "Please enter the command again" << std::endl;
            continue;
        }
    }
}