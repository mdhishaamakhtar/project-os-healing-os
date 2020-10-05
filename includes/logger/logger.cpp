#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
using namespace std;

/*This is Logger File 
to use this logger you need to instantiate LoggerClass and using logInfo() function
with two strings as arguments ex: log("command","command category") and the time stamp is appended to this
OutPut Example:
command|category|time
Sample.txt:
ls|Command_System|1601834132
cd|Command_System|1601834132

here:
"|" being the delimiter
*/

class LoggerClass
{
public:
    string commandName;
    string category;
    time_t systime;
    friend ofstream &operator<<(ofstream &ofs, LoggerClass &s);
    void logInfo(std::string a,std::string b)
    {
        LoggerClass s;
        s.commandName = a;
        s.category = b;
        s.systime =	time(NULL);
        ofstream ofs("sample.txt", ios::app);

        ofs<<s;
            
        ofs.close();
    }
};

ofstream &operator<<(ofstream &ofs, LoggerClass &s)
{
    ofs << s.commandName <<"|";
    ofs << s.category << "|";
    ofs << s.systime << endl;
    return ofs;
}
//samplecall in main::
/*int main()
{
    LoggerClass h;

    h.logInfo("yo","hello");
    h.logInfo("why","nolo");
}*/
