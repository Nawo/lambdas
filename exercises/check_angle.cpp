#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

float PI = 3.14159;

int main()
{

    auto check_angle = [](std::string string_) mutable -> float
    {

        std::string hour_;
        hour_.push_back(string_[0]);
        hour_.push_back(string_[1]);

        if(hour_ == "12") { hour_ = "0"; }

        std::string minute_;
        minute_.push_back(string_[3]);
        minute_.push_back(string_[4]);

        char type_ = string_[5];

        float result_ = 0;

        if(type_ == 'd') 
            result_ = std::abs( ( (360 / 12) * std::stoi(hour_)) - ( (360 / 60) * std::stoi(minute_) ) );

        else if(type_ == 'r')
            result_ = std::abs( ( ( ( (360 / 12) * std::stoi(hour_)) - ( (360 / 60) * std::stoi(minute_) ) ) * PI) / 180);

        result_ = (int)(result_ * 100 + 0.5) / 100.0;
        
        return result_;    

    };

    std::cout << check_angle("12:00d") << std::endl;
    std::cout << check_angle("12:30r") << std::endl;

    return 0;
}