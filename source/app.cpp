#include<iostream>
#include"./../includes/rainbow/rainbow.h"

using namespace std;

int main(){
    cout << rainbow::underline(rainbow::bold(rainbow::red("SELF HEALING OS"))) << endl << endl;   
    return 0;
}