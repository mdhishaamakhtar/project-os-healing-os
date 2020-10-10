#include"rainbow.h"
#include<iostream>
#include<string>
#include <iomanip>

using namespace std;


string rainbow::orange(string str){
    string x;
    x.append("\e[33m");
    x.append(str);
    x.append("\e[0m");
    return x;
}

string rainbow::green(string str){
    string x;
    x.append("\e[32m");
    x.append(str);
    x.append("\e[0m");
    return x;
}

string rainbow::grey(string str){
    string x;
    x.append("\e[90m");
    x.append(str);
    x.append("\e[0m");
    return x;
}


string rainbow::red(string str){
    string x;
    x.append("\e[31m");
    x.append(str);
    x.append("\e[0m");
    return x;
}

string rainbow::bold(string str){
	string x;
	x.append("\033[1m");
	x.append(str);
	x.append("\033[0m");
	return x;
}

string rainbow::italic(string str){
	string x;
	x.append("\e[3m");
	x.append(str);
	x.append("\e[0m");
	return x;
}

string rainbow::underline(string str){
	string x;
	x.append("\e[4m");
	x.append(str);
	x.append("\e[0m");
	return x;
}

string rainbow::strike(string str){
	string x;
	x.append("\e[9m");
	x.append(str);
	x.append("\e[0m");
	return x;
}


void rainbow::log(string module, string context, string command){ 
    string firstSegment = "[" + rainbow::green("logger") + "] ";
    string contextSegment = "[" + rainbow::italic(context)  + "] ";
    string lastSegment = " " + rainbow::grey(command);
    cout << firstSegment << contextSegment << lastSegment << endl;
}