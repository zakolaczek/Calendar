//author zakolaczek

#include <iostream>
#include <windows.h>
#include "output.cpp"
using namespace std;

int main(){
    int seconds;
    int current = 0;
    cout << "After how many seconds do you want the program to end? : ";
    cin >> seconds;
    Sleep(500);
    system("cls");
    //loop refreshing time every second
    while(current < seconds){
        showDate();
        cout << "\n\n";
        showSheet();
        Sleep(1000);
        current += 1;
        system("cls");
    }
    system("pause");
    return 0;
}