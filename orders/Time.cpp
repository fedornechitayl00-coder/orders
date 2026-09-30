#include "Time.h"

Time::Time()
{
    tm info = {};
    auto curent = time(0);

    localtime_s(&info, &curent);

    hour = info.tm_hour;
    minutes = info.tm_min;
    seconds = info.tm_sec;
    format = true;// true = utc (24-hours),    false = am/pm (12-hours),  Тільки для виведення часу на екран
}

Time::Time(int hour, int minutes, int seconds, bool format)
{
    this->hour = hour;
    this->minutes = minutes;
    this->seconds = seconds;
    this->format = format;
}

void Time::setHour(int hour)
{
    if (hour < 24 && hour >= 0) {
        this->hour = hour;
    }
}

int Time::getHour() const
{
    return hour;
}

void Time::setMinutes(int minutes)
{
    if (minutes < 60 && minutes>=0) {
        this->minutes = minutes;
    }
}

int Time::getMinutes() const
{
    return minutes;
}

void Time::setSeconds(int seconds)
{
    if (seconds < 60 && seconds>=0) {
        this->seconds = seconds;
    }
}

int Time::getSeconds() const
{
    return seconds;
}

void Time::setFormat(bool format)
{
    this->format = format;
}

bool Time::getFormat() const
{
    return format;
}

bool Time::valid() const
{
    return (hour <=23 && hour >= 0 && minutes <= 59 && minutes >= 0 && seconds <= 59 && seconds >= 0);
}

void Time::tickTime()
{
    if (seconds < 59)
    {
        seconds += 1;
    }
    else {
        seconds = 0;
        if (minutes < 60) minutes += 1;
        else {
            minutes = 0;
            if (hour < 24) hour += 1;
            else hour = 0;
        }
    }
}

void Time::untickTime()
{
    if (seconds < 60 && seconds >0 )
    {
        seconds -= 1;
    }
    else {
        seconds = 59;
        if (minutes < 60 && minutes >0) minutes -= 1;
        else {
            minutes = 59;
            if (hour < 24 && hour > 0) hour -= 1;
        }
    }
}

void Time::showTime() const
{
    std::cout << "___________\n";
    if (format == true) {
        std::cout << "| " << hour;
    }
    else {
        if (hour <= 12) std::cout << "| " << hour << "a.m.";
        else std::cout << hour - 12 << "p.m.";
    }

    std::cout << ":" << minutes << ":" << seconds << "| " << std::endl;
    std::cout << "___________\n";
}

bool Time::operator==(const Time& obj) const&
{
    if (this->hour == obj.hour && this->minutes == obj.minutes && this->seconds == obj.seconds) {
        return true;
    }
    else {
        return false;
    }
}

bool Time::operator!=(const Time& obj) const&
{
    return !(*this == obj);
}

bool Time::operator<(const Time& obj) const&
{
    if (hour != obj.hour) { return hour < obj.hour; }
    if (minutes != obj.minutes) { return minutes < obj.minutes; }
    if (seconds != obj.seconds) { return seconds < obj.seconds; }
    return false;
}

bool Time::operator>(const Time& obj) const&
{
    return *this < obj;
}

bool Time::operator>=(const Time& obj) const&
{
    return !(*this < obj) || (*this==obj);
}

bool Time::operator<=(const Time& obj) const&
{
    return !(*this > obj) || (*this == obj);
}

Time& Time::operator+=(float s)
{
    this->seconds += s;
    while (this->seconds > 59) {
        this->seconds -= 60;
        this->minutes++;
    }
    while (this->minutes > 59) {
        this->minutes -= 60;
        this->hour++;
    }
    while (this->hour > 23) {
        this->hour -= 24;
    }
    return *this;
}

Time& Time::operator-=(float s)
{
    this->seconds -= s;
    while (this->seconds < 0) {
        this->seconds += 60;
        this->minutes--;
    }
    while (this->minutes < 0) {
        this->minutes += 60;
        this->hour--;
    }
    while (this->hour < 0) {
        this->hour += 24;
    }
    return *this;
}

Time& Time::operator+=(int m)
{
    this->minutes += m;
    while (this->minutes > 59) {
        this->minutes -= 60;
        this->hour++;
    }
    while (this->hour > 23) {
        this->hour -= 24;
    }
    return *this;
}

Time& Time::operator-=(int m)
{
    this->minutes -= m;
    while (this->minutes < 0) {
        this->minutes += 60;
        this->hour--;
    }
    while (this->hour < 0) {
        this->hour += 24;
    }
    return *this;
}

Time& Time::operator+=(long h)
{
    this->hour += h;
    while (this->hour > 23) {
        this->hour -= 24;
    }
    return *this;
}

Time& Time::operator-=(long h)
{
    this->hour -= h;
    while (this->hour < 0) {
        this->hour += 24;
    }
    return *this;
}

Time Time::operator+(float s) const&
{
    Time tmp = *this;
    tmp += s;
    return tmp;
}

Time Time::operator-(float s) const&
{
    Time tmp = *this;
    tmp -= s;
    return tmp;
}

Time Time::operator+(int m) const&
{
    Time tmp = *this;
    tmp += m;
    return tmp;
}

Time Time::operator-(int m) const&
{
    Time tmp = *this;
    tmp -= m;
    return tmp;
}

Time Time::operator+(long h) const&
{
    Time tmp = *this;
    tmp += h;
    return tmp;
}

Time Time::operator-(long h) const&
{
    Time tmp = *this;
    tmp -= h;
    return tmp;
}

Time& Time::operator--()
{
    (*this) -= 1;
    return *this;
}

Time Time::operator--(int)
{
    Time tmp = *this;
    --(*this);
    return tmp;
}

Time& Time::operator++()
{
    (*this) += 1;
    return *this;
}

Time Time::operator++(int)
{
    Time tmp = *this;
    ++(*this);
    return tmp;
}

std::ostream& operator<<(std::ostream& out, const Time& obj) {
    if (obj.getFormat()) {
        out << obj.getHour() << ":" << obj.getMinutes();
    }
    else {
        if (obj.getHour() <= 12) out << obj.getHour() << " a.m.";
        else out << (obj.getHour() - 12) << " p.m.";
        out << ":" << obj.getMinutes();
    }
    return out;
}