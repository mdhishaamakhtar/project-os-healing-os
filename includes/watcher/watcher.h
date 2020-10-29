#ifndef WATCHER
#define WATCHER
#include <vector>
#include <string>

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
            ":cloud pull",
            ":cloud push",
            ":logs show",
            ":logs clean"
        };

        /**Function to enter a command */
        static string listenForCommand(string context);

        /**
         * Function to call the utility function to
         * be implemented when the functions are ready
         */
        static void taskDispatcher(vector<string> command);

        /** Functon to check if command is allowed or not */
        bool ifValidInternalCommand(string command);
}; 

#endif