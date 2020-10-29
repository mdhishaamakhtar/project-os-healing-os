#ifndef LOGGER
#define LOGGER
#include <string>
#include <time.h>
#include <vector>

using namespace std;

/**
 * @class: LoggerModule
 * @description: Module to handle logging operations to store all commands executed
 * which can be later used to bring the system in the main state.
 * 
 * The data is stored as a plain file, using ~~|~~ as a delimiter
 * ex: log("command category","command") 
 * 
 * output ex: 
 * command category|comand|timestemp
 * 
 * Sample.txt:
 * Command_System~~|~~ls~~|~~1601834132
 * Command_System~~|~~cd~~|~~1601834132
 * 
 * here ~~|~~ is being used as delimiter
 */

class LoggerModule {
    public:
        string commandName;
        string category;
        time_t systime;
        static void save(string context, string command);
        friend ofstream &operator<<(ofstream &ofs, LoggerModule &s);
        static vector<string> readAll();
};

#endif 
