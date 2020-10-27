#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <time.h>
#include "./../rainbow/rainbow.h"
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
class LoggerModule{
    public:
        string commandName;
        string category;
        time_t systime;
        friend ofstream &operator<<(ofstream &ofs, LoggerModule &s);
        void save(string context,string command);
        vector<string> readAll();
};

/** overloading shift operator to write data **/
ofstream &operator<<(ofstream &ofs, LoggerModule &s){
    ofs << s.commandName <<"|";
    ofs << s.category << "|";
    ofs << s.systime << endl;
    return ofs;
}


/* readAll() function returns all the commands from beginning of usage of the program*/
vector<string> LoggerModule::readAll(){
    ifstream file("logs.txt");
    vector<string> commands;

    if (file.is_open()){
        std::string entry;
        while (getline(file, entry)){
            commands.push_back(entry);
        }
        file.close();
    }

    return commands;
}

/**
 * @method 
 * @description: to write a log entry into persistant storage, with timestamp and 
 * category to which it belongs
 */
void LoggerModule::save(string context, string command){
    LoggerModule logger;
    logger.category = context;
    logger.commandName = command;
    logger.systime = time(NULL);
    ofstream ofs("logs.txt", ios::app);
    // rainbow::log("logger",context, command);
    ofs << logger;
    ofs.close();
}
