#incude "sad.h"

bool sad(string day, int num){
    if(day == "monday" && num == 12) return true;
    if(day == "tuesday" && num > 95) return true;
    if(day == "wednesday" && num == 34) return true;
    if(day == "thursday" && num == 0) return true;
    if(day == "friday" && num % 2 == 0) return true;
    if(day == "saturday" && num == 56) return true;
    if(day == "sunday" && abs(num) == 666) return true;
    return false;
}