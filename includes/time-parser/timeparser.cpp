#include<iostream>
#include<string>
#include <chrono>
#include "date.h"
using namespace std;
using namespace std::chrono;
using namespace date;

/**
 * @class TimeParser
 * To parse the time taken in linux format and convert it to a readable one
 * Usage in Main Function:
 * Timeparser t;
 * auto time = t.parseTime(1602325928);
 * value of time: 2020-10-10
 */
class TimeParser {
public:
    /**
     * @param time_t s
     * Declaration of parseTime function
     */
    date::year_month_day parseTime(time_t s);
};

/**
 * @param time_t time
 * Takes in unix time as a parameter
 * Returns the date in a readable format
 * Example input: 1602325928
 * Example output: 2020-10-10
 */
date::year_month_day TimeParser::parseTime(time_t time) {
    auto sysTime = std::chrono::system_clock::from_time_t(time);
    auto date = year_month_day(floor<days>(sysTime));
    return date;
}
