#include<iostream>
#include<string>
#include <chrono>
#include "date.h"
using namespace std;
using namespace std::chrono;
using namespace date;
class TimeParser {
    public:
        date::year_month_day parseTime(time_t s);
};

date::year_month_day TimeParser::parseTime(time_t time){
    auto sysTime = std::chrono::system_clock::from_time_t(time);
    auto date = year_month_day(floor<days>(sysTime));
    return date;
}