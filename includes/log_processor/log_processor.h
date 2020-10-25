#ifndef log_processor
#define log_processor

#include<string>
#include<vector>

using namespace std;

/*
Class "LogEntry" initialized with attributes of a command entered in the Command Line:
1.Command Type: commandType
2.Command: command
3.Time stamp: timestamp

Constructor Initializied within the class.
*/

class LogEntry{
    public:
        string commandType;
        string command;
        unsigned long long int timestamp;
        
        LogEntry(string commandType, string command, string timestamp);
};

/*
Class "LogProcessor" initialized with private Vector of type string 
-> this will be used to process the information of cammand into tokenized form using a delimiter.
->vector of type of the class "LogEntry" itself will let us create an "array" of its objects
and then subsequently fetch their timestamp.
*/

class LogProcessor{
    private: 
        vector<string> tokenizeEntry(string entry);
    public:
        vector<LogEntry> entryStorage;
        LogProcessor(vector<string> entries);
        vector<LogEntry> Fetch(int timestamp);
};

#endif