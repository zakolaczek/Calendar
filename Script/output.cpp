//author zakolaczek

#include <iostream>
#include <vector>
#include <windows.h>
#include "formatAndCheck.cpp"
using namespace std;

//shows on a screen current date and current time (using color text in console)
void showDate(){
    formatDate format;
    getDateFunctions get;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    vector<int> date =  get.getDate();
    string weekDay = format.whatWeekDay(date);
    SetConsoleTextAttribute(h, 14);
    cout << "\tCurrent date: ";
    SetConsoleTextAttribute(h, 12);
    cout << weekDay << ", ";
    for(int i = 0; i < 3; i++){
        if(date[i] < 10){
            cout << "0";
        }
        cout << date[i];
        if(i < 2){
            cout << ".";
        }
    }
    cout << endl;
    SetConsoleTextAttribute(h, 12);
    cout << "\tCurrent time: ";
    SetConsoleTextAttribute(h, 14);
    for(int i = 3; i < date.size() - 1; i++){
        if(date[i] < 10){
            cout << "0";
        }
        cout << date[i];
        if(i < 5){
            cout << " : ";
        }
    }   
}

//calculates how many spaces for each day in calendar sheet
string calculateSpace(int weekDay){
    string space = " ";
    if(weekDay == 1){
        return space;
    }
    for(int i = 2; i <= weekDay; i++){
        space += "     ";
        if(i == weekDay){
            return space;
        }
    }
    return space;    
}

//calculates first weekday of month
int calculateFirstDay(int day, int weekday){
    if(day > 7){
        for(int i = 0; day - 7 > 0; i++){
            day -= 7;
        }
    }
    if(day <= weekday ){     
        day -= weekday;
        day = day * (-1);
    }else{
        day -= 7;
        day -= weekday;
        day = day * (-1);   
    }
    return day + 1 ; 
}

//shows calendar sheet on a screen (with color text)
void showSheet(){
    getDateFunctions get;
    formatDate format;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    vector<int> date = get.getDate();
    string empty;
    string month = format.whatMonth(date);
    int monthsMaxdays = format.howMuchDays(date[1], date[2]);
    int currentDay = date[0];
    int currentWeekDay = calculateFirstDay(currentDay, date[date.size() - 1]);
    int displayDay = 1;
    string start = calculateSpace(currentWeekDay);
    cout << "\n\t\t";
    SetConsoleTextAttribute(h, 14);
    cout << month << " " << date[2] << endl << endl;
    SetConsoleTextAttribute(h, 12);
    cout << "\tMon  Tue  Wed  Thu  Fri  Sat  Sun" << endl << "\t" << start;
    for(displayDay; displayDay <= monthsMaxdays; displayDay ++){
        if(currentWeekDay > 7){
            cout << endl << "\t ";
            currentWeekDay = 1;
        }
        if(displayDay < 10){
            empty = "    ";
        }else{
            empty = "   ";
        }
        if(displayDay == currentDay){
            SetConsoleTextAttribute(h, 12);
            cout << displayDay << empty;
            SetConsoleTextAttribute(h, 14);
        }else{
            SetConsoleTextAttribute(h, 14);
            cout << displayDay << empty;
        }
        currentWeekDay ++; 
    }
}