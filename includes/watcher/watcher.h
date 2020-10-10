#include <iostream>
#include <vector>
#include <string>
/**
 * Watcher Class
 */
class Watcher {
public:
    /**
     * Vector which stores all commands available for the User
     * More to be added when core utility is implemented
     */
    std::vector<std::string> available_commands = {":checkpoint create",":checkpoint revert",":branch new",":branch switch",":branch delete",":branch accept",":cloud attach",":cloud sync"};
    /**
     * Function to enter a command
     */
    std::string enter_command();
    /**
     * Function to call the utility function
     * To be implemented when the functions are ready
     */
    void call_utility(std::string command);
    /**
     * Functon to check if command is allowed or not
     */
    bool command_checker(std::string command);
};
/**
 * Implementation of enter_command
 */
std::string Watcher::enter_command() {
    std::string command;
    std::getline(std::cin, command);
    return command;
}
/**
 * Implementation of command checker: Uses Linear Search
 */
bool Watcher::command_checker(std::string command) {
    for (auto cmd : Watcher::available_commands) {
        if (cmd == command) {
            return true;
        }
    }
    return false;
}