
#include "TimeOfDay.h"
#include <iostream>

using std::cout;
using std::endl;

TimeOfDay::TimeOfDay(int hour, int minute, int second) {
    SetHour(hour);
    SetMinute(minute);
    SetSecond(second);
}

void TimeOfDay::Print() const {

    if(getTwelveHour(GetHour()) > 9)
        cout << getTwelveHour(GetHour());
    else
        cout << "0" << getTwelveHour(GetHour());
    if(GetMinute() > 9)
        cout << ":" << GetMinute();
    else
        cout << ":0" << GetMinute();

    if(GetHour() > 11)
        cout << " p.m.";
    else
        cout << " a.m.";
    cout << endl;


}

void TimeOfDay::Print(bool militaryTime) const {

    if (militaryTime) {
        if(GetHour() > 9)
            cout << GetHour();
        else
            cout << "0" << GetHour();
        if(GetMinute() > 9)
            cout << ":" << GetMinute() << ":";
        else
            cout << ":0" << GetMinute();
    }


}

void TimeOfDay::Print(bool militaryTime = false, bool showSeconds = false) const {
    if (militaryTime) {
        if (GetHour() > 9)
            cout << GetHour();
        else
            cout << "0" << GetHour();

        if (GetMinute() > 9)
            cout << ":" << GetMinute();
        else
            cout << ":0" << GetMinute();

        if (showSeconds) {
            if (GetSecond() > 9)
                cout << ":" << GetSecond();
            else
                cout << ":0" << GetSecond();
        }
    }
    else {

        if (getTwelveHour(GetHour()) > 9)
            cout << getTwelveHour(GetHour());
        else
            cout << "0" << getTwelveHour(GetHour());

        if (GetMinute() > 9)
            cout << ":" << GetMinute();
        else
            cout << ":0" << GetMinute();

        if (showSeconds) {
            if (GetSecond() > 9)
                cout << ":" << GetSecond();
            else
                cout << ":0" << GetSecond();
        }

        if (GetHour() >= 12)
            cout << " p.m.";
        else
            cout << " a.m.";
    }
    cout << endl;
}

