#include "Date.h"

Date::Date()
{
    tm info = {};
    auto curent = time(0);
#if dateWindows == 1
    localtime_s(&info, &curent);
#elif dateWindows == 0
    tm* p = localtime(&curent);// CLION
    info = *p;
#endif

    year = info.tm_year + 1900;
    month = info.tm_mon + 1;
    day = info.tm_mday;

}

Date::Date(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

bool Date::isLeapYear() const
{
    if (year % 4 == 0 && year % 100 != 0 || year % 100 == 0 && year % 400 == 0) return true;
    else
        return false;
}

int Date::monthDays() const
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
    else if (month == 4 || month == 6 || month == 9 || month == 11)return 30;
    else if (month == 2)return isLeapYear() ? 29 : 28;

    return 0;
}

void Date::nextDate()
{
    if (day == 31 && month == 12)
    {
        day = 1; month = 1; year++;
    }
    else if (day == monthDays())
    {
        day = 1; month++;
    }
    else day++;
}

void Date::prevDate()
{
    if (day == 1 && month == 1)
    {
        day = 31; month = 12; year--;
    }
    else if (day == 1)
    {
        month--; day = monthDays();
    }
    else day--;
}

void Date::setYear(int year)
{
    this->year = year;
}

int Date::getYear() const
{
    return year;
}

void Date::setMonth(int month)
{
    if (month >= 1 && month <= 12)
    {
        this->month = month;
    }
}

int Date::getMonth() const
{
    return month;
}

void Date::setDay(int day)
{
    if (day >= 1 && day <= monthDays())
    {
        this->day = day;
    }
}

int Date::getDay() const
{
    return day;
}

void Date::showDate() const
{
    std::cout << day / 10 << day % 10 << " ." << month / 10 << month % 10 << " ." << year << std::endl;
}

bool Date::valid() const
{
    return (month >= 1 && month <= 12 && day >= 1 && day <= monthDays());
}

std::string Date::toString() const
{
    return std::to_string(day / 10) + std::to_string(day % 10) + "." +
    std::to_string(month / 10) + std::to_string(month % 10) + "." +
    std::to_string(year);
}


bool Date::operator==(const Date& obj) const&
{
    //d1==d2
    //d1 - this, d2 - obj
    if (this->day == obj.day && this->month == obj.month && this->year == obj.year) {
        return true;
    }
    else {
        return false;
    }
}

bool Date::operator!=(const Date& obj) const&
{
    //if (this->day != obj.day || this->month != obj.month || this->year != obj.year) {
    //    return true;
    //}
    //else {
    //    return false;
    //}

    return !(*this == obj);  //коротший вариант
}

bool Date::operator>(const Date& obj) const&
{
    if (this->year > obj.year) return true;
    else if (this->year == obj.year && this->month > obj.month) return true;
    else if (this->year == obj.year && this->month == obj.month && this->day > obj.day) return true;
    else return false;
}

bool Date::operator<(const Date& obj) const&
{
    return !(*this > obj) && (*this != obj);
}

bool Date::operator>=(const Date& obj) const&
{
    return !(*this> obj) || (*this == obj);
}

bool Date::operator<=(const Date& obj) const&
{
    return !(*this < obj) || (*this == obj);
}

Date& Date::operator+=(int days)
{
    for (int i = 0; i < days; i++) {
        this->nextDate();
    }
    return *this;
}

Date& Date::operator-=(int days)
{
    for (int i = 0; i < days; i++) {
        this->prevDate();
    }
    return *this;
}

Date& Date::operator+=(float months)
{
    this->month += months;
    while (this->month > 12) {
        this->month -= 12; 
        this->year++;
    }
    return *this;
}

Date& Date::operator-=(float months)
{
    this->month -= months;
    while (this->month < 0) {
        this->month += 12;
        this->year--;
    }
    return *this;
}

Date& Date::operator+=(long years)
{
    this->year += years;
    return *this;
}

Date& Date::operator-=(long years)
{
    this->year -= years;
    return* this;
}

Date Date::operator+(int days) const&
{
    Date tmp = *this;
    tmp += days;
    return tmp;
}

Date Date::operator-(int days) const&
{
    Date tmp = *this;
    tmp -= days;
    return tmp;
}

Date Date::operator+(float months) const&
{
    Date tmp = *this;
    tmp += months;
    return tmp;
}

Date Date::operator-(float months) const&
{
    Date tmp = *this;
    tmp -= months;
    return tmp;
}

Date Date::operator+(long years) const&
{
    Date tmp = *this;
    tmp += years;
    return tmp;
}

Date Date::operator-(long years) const&
{
    Date tmp = *this;
    tmp -= years;
    return tmp;
}

Date& Date::operator--()
{
    (*this) -= 1;
    return *this;
}

Date Date::operator--(int)
{
    Date tmp = *this;
    --(*this);
    return tmp;
}

Date& Date::operator++()
{
    //(*this) += 1;
    //return *this;
    this->nextDate();
    return *this;
}

Date Date::operator++(int)
{
    Date tmp = *this;
    ++(*this);
    // or rhis->nextDate();
    return tmp;
}

std::ostream& operator<<(std::ostream& os, const Date& t)
{
    os << t.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Date& t)
{
    do {
        std::cout << " yyyy mm dd \n";
        is >> t.year >> t.month >> t.day;
    } while (!t.valid()); {
        return is;
    }
}

Date operator+(int days, const Date& a)
{
    return a + days;
}

Date operator-(int days, const Date& a)
{
    return a - days;;
}

Date operator+(float months, const Date& a)
{
    return a + months;
}

Date operator-(float months, const Date& a)
{
    return a - months;
}

Date operator+(long years, const Date& a)
{
    return a + years;
}

Date operator-(long years, const Date& a)
{
    return a- years;
}
