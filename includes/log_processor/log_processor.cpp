#include"log_processor.h"
#include<iostream>
#include <sstream>
#include<vector>
#include<string>

using namespace std;
/*the log_processor header file includes the Classes and their fucntions in USE in this file*/

/*constructor intialized in header file assigned attributes accordingly*/
LogEntry::LogEntry(string commandType, string command, string timestamp){
    this->command = command;
    this->commandType = commandType;
    this->timestamp = stol(timestamp, nullptr, 10);
}

/** constructor to load all entries, parse them and store them **/
LogProcessor::LogProcessor(vector<string> entries){
    vector<string>temp;
    
    for(string entry:entries){
        temp.clear();
        temp = this->tokenizeEntry(entry);
        LogEntry newEntryObject = LogEntry(temp[0], temp[1], temp[2]);
        this->entryStorage.push_back(newEntryObject);
    }    
}
/* Function derived from Class "LogProcessor" to add delimiters (here "|") in between the attributes of each object entry*/
vector<string> LogProcessor::tokenizeEntry(string line){
    vector<string> tokens;
    stringstream check1(line); 
    string intermediate; 

    while(getline(check1, intermediate, '|')){ 
        tokens.push_back(intermediate); 
    } 
 
    return tokens;
} 

/** function to get all entries from a particular checkpoint **/
vector<LogEntry> LogProcessor::Fetch(int timestamp){
    vector<LogEntry> entries;
    for(auto entry : this->entryStorage){
        if(entry.timestamp >= timestamp){
            entries.push_back(entry);
        }
    }
    return entries;
}