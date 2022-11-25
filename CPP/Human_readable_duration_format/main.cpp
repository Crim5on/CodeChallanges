// source: https://www.codewars.com/kata/52742f58faf5485cae000b9a/train/cpp
/*
    For seconds = 62, your function should return 
        "1 minute and 2 seconds"
    For seconds = 3662, your function should return
        "1 hour, 1 minute and 2 seconds"
*/

#include <iostream>
#include <string>


static inline void format_append(int number, std::string unit, std::string& result_string)
{
    if (number == 1){
        result_string.append(std::to_string(number) + " " + unit + ", ");
    }
    else if(number > 1){
        result_string.append(std::to_string(number) + " " + unit + "s, ");
    }
}


std::string format_duration(int seconds) 
{
    if(seconds == 0){
        return "now";
    }

    int minutes = seconds / 60;
    seconds = seconds % 60;
    int hours = minutes / 60;
    minutes = minutes % 60;
    int days = hours / 24;
    hours = hours % 24;
    int years = days / 365;
    days = days % 365;

    std::string result_string;
    format_append(years, "year", result_string);
    format_append(days, "day", result_string);
    format_append(hours, "hour", result_string);
    format_append(minutes, "minute", result_string);
    format_append(seconds, "second", result_string);
    
    // remove trailing ", "
    result_string.pop_back();
    result_string.pop_back();

    // replace last "," with " and"
    size_t last_comma_position = result_string.find_last_of(",");
    if (last_comma_position != std::string::npos){
        result_string.erase(last_comma_position, 1);
        result_string.insert(last_comma_position, " and");
    }

    return result_string;
}

 

int main(void)
{
    std::string result = format_duration(1);
    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}