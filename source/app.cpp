#include<iostream>
#include"./../includes/rainbow/rainbow.h"
#include"./../includes/logger/logger.cpp"
using namespace std;

int main(){
    cout << rainbow::underline(rainbow::bold(rainbow::red("SELF HEALING OS"))) << endl << endl; 
    
    cout << rainbow::bold("Logger Usage") << endl;
    
    LoggerModule logger;
    logger.save("system", "ls");
    logger.save("system", "mkdir directory");
    logger.save("system", "cat commands.txt");
    logger.save("internal", ":checkpoint create");
    logger.save("internal", ":checkpoint delete");
      
    return 0;
}