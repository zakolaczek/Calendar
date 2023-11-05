//author zakolaczek

#include <ctime>
#include <vector>
using namespace std;

//constains public methods about getting the date from system
class getDateFunctions{
public:

    //Checks current time 
    tm checkTime(){
        time_t current = time(0);
        tm now = *localtime(&current);
        return now;
    }

    //returns current year
    int getYear(tm year){
        int currentYear = year.tm_year + 1900;
        return currentYear;
    }

    //returns current month
    int getMonth(tm month){
        int currentMonth = month.tm_mon + 1;
        return currentMonth;
    }

    //returns current day
    int getDay(tm day){
        int currentDay = day.tm_mday;
        return currentDay;
    }

    //returns current hour
    int getHour(tm hour){
        int currentHour = hour.tm_hour;
        return currentHour;
    }

    //returns current minute
    int getMinute(tm minute){
        int currentMinute = minute.tm_min;
        return currentMinute;
    }

    //returns current weekday (if it is sunday returns 7)
    int getWeekday(tm day){
        int currentWeekDay = day.tm_wday;
        if(currentWeekDay == 0){
            currentWeekDay = 7;
        }
        return currentWeekDay;
    }

    //returns current second
    int getSeconds(tm sec){
        int seconds = sec.tm_sec;
        return seconds;
    }

    //returns vector containing current date
    vector<int> getDate(){
        tm now = checkTime();
        vector<int> date;
        date.push_back(getDay(now));
        date.push_back(getMonth(now));
        date.push_back(getYear(now));
        date.push_back(getHour(now));
        date.push_back(getMinute(now));
        date.push_back(getSeconds(now));
        date.push_back(getWeekday(now));
        return date;
    }
};

//contains public methods formatting the date collected from system
class formatDate{
public:

    //returns an english name of weekday(for 1 returns Monday etc.)
    string whatWeekDay(vector<int> date){
        switch(date[date.size() - 1]){
            case 1:
                return "Monday";
                break;
            case 2:
                return "Tuesday";
                break;
            case 3:
                return "Wednesday";
                break;
            case 4:
                return "Thursday";
                break;
            case 5:
                return "Friday";
                break;
            case 6:
                return "Saturday";
                break;
            case 7:
                return "Sunday";
                break;
        }
    }

    //returns an english name of month(for 1 returns January etc.)
    string whatMonth(vector<int> date){
        switch(date[1]){
            case 1:
                return "January";
                break;
            case 2:
                return "February";
                break;
            case 3:
                return "March";
                break;
            case 4:
                return "April";
                break;
            case 5:
                return "May";
                break;
            case 6:
                return "June";
                break;
            case 7:
                return "July";
                break;
            case 8:
                return "August";
                break;
            case 9:
                return "September";
                break;
            case 10:
                return "October";
                break;
            case 11:
                return "November";
                break;
            case 12:
                return "December";
                break;
        }
    }

    //Checks that something is on vector
    bool isOnList(vector<int> list, int toFind){
        for(const int x : list){
            if(x == toFind){
                return true;
            }
        }
        return false;
    }

    //Checks that year is leap
    bool isLeapYear(int year){
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ){
            return true;
        }else{
            return false;
        }
    }

    //Returns how many days contains a month(for January returns 31 etc.)
    int howMuchDays(int month, int year){
        int days;
        vector<int> longer = {1,3,5,7,8,10,12};
        vector<int> shorter = {4,6,9,11};
        if(isOnList(longer, month)){
            days = 31;
        }else if(isOnList(shorter, month)){
            days = 30;
        }else{
            if(isLeapYear(year)){
                days = 29;
            }else{
                days = 28;
            }
        }
        return days;
    }
};