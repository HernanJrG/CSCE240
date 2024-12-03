
#include "TimeInterval.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

TimeInterval::TimeInterval() {}

TimeInterval::TimeInterval(const TimeOfDay& start, const TimeOfDay& end) {
    if (isLaterInDay(start, end)) {
        startTime = start;
        endTime = start;
    } else {
        startTime = start;
        endTime = end;
    }
}

TimeInterval::TimeInterval(const TimeOfDay& start, int length, const string& units) {
    startTime = start;
    endTime = calculateEndTime(start, length, units);
}

void TimeInterval::SetStartTime(const TimeOfDay& start) {
    if (!isLaterInDay(start, endTime)) {
        startTime = start;
    }
}

void TimeInterval::SetEndTime(const TimeOfDay& end) {
    if (!isLaterInDay(startTime, end)) {
        endTime = end;
    }
}

void TimeInterval::SetEndTime(int length, const string& units) {
    TimeOfDay newEnd = calculateEndTime(startTime, length, units);
    if (newEnd.GetHour() != startTime.GetHour() ||
        newEnd.GetMinute() != startTime.GetMinute() ||
        newEnd.GetSecond() != startTime.GetSecond()) {
        endTime = newEnd;
    }
}

bool TimeInterval::isLaterInDay(const TimeOfDay& t1, const TimeOfDay& t2) const {
    if (t1.GetHour() > t2.GetHour()) return true;
    if (t1.GetHour() < t2.GetHour()) return false;
    if (t1.GetMinute() > t2.GetMinute()) return true;
    if (t1.GetMinute() < t2.GetMinute()) return false;
    return t1.GetSecond() > t2.GetSecond();
}

TimeOfDay TimeInterval::calculateEndTime(const TimeOfDay& start, int length, const string& units) const {
    int totalSeconds = 0;
    int startSeconds = start.GetHour() * 3600 + start.GetMinute() * 60 + start.GetSecond();

    if (units == "seconds") {
        totalSeconds = length;
    } else if (units == "minutes") {
        totalSeconds = length * 60;
    } else if (units == "hours") {
        totalSeconds = length * 3600;
    } else {
        return start;
    }

    int endSeconds = startSeconds + totalSeconds;

    if (endSeconds >= 24 * 3600) {
        return start;
    }

    int hours = endSeconds / 3600;
    int minutes = (endSeconds % 3600) / 60;
    int seconds = endSeconds % 60;

    return TimeOfDay(hours, minutes, seconds);
}

void TimeInterval::Print(bool militaryTime, bool showSeconds) const {
    cout << "Start time: ";
    startTime.Print(militaryTime, showSeconds);
    cout << "End time: ";
    endTime.Print(militaryTime, showSeconds);
}