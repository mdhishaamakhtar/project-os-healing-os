#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>

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
        friend ifstream &operator>>(ifstream &ifs, LoggerModule &s);
        void save(std::string a,std::string b);
};

/** overloading shift operator to write data **/
ofstream &operator<<(ofstream &ofs, LoggerModule &s){
    ofs << s.commandName <<"~~|~~";
    ofs << s.category << "~~|~~";
    ofs << s.systime << endl;
    return ofs;
}

/* overloading insertion operator to read data from file*/
ifstream &operator>>(ifstream &ifs, LoggerModule &s)
{

    ifs >> s.commandName;
    ifs >> s.category;
    ifs >> s.systime;
    return ifs;
}
/*read() function prints all the commands from beginning of usage of the program*/
void LoggerModule::read()
    {

        LoggerModule s;
        std::ifstream file("logs.txt");
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                // using printf() in all tests for consistency
                printf("%s\n", line.c_str());
            }
            file.close();
        }
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
    ofs << logger;
    ofs.close();
}