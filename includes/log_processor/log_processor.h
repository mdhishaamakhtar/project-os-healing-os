#ifndef log_processor
#define log_processor

#include<string>
#include<vector>

using namespace std;

class LogEntry{
    public:
        string commandType;
        string command;
        unsigned long long int timestamp;
        
        LogEntry(string commandType, string command, string timestamp);
};

class LogProcessor{
    private: 
        vector<string> tokenizeEntry(string entry);
    public:
        vector<LogEntry> entryStorage;
        LogProcessor(vector<string> entries);
        vector<LogEntry> Fetch(int timestamp);
};

#endif