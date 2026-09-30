#pragma once
#include <iostream>
#include <string>
#include <ctime>


class Time
{
	int hour;
	int minutes;
	int seconds;
	bool format;// true = utc (24-hours),    false = am/pm (12-hours),  Тільки для виведення часу на екран
public:
	Time(); // Поточний локальний час
	Time(int hour, int minutes, int seconds, bool format = true);

	void setHour(int hour);
	int getHour()const;
	void setMinutes(int minutes);
	int getMinutes()const;
	void setSeconds(int seconds);
	int getSeconds()const;
	void setFormat(bool format);
	bool getFormat()const;

	
	bool valid()const; //Перевірка на правильність данних
	void tickTime(); //Додавання однієї секунди
	void untickTime(); //Віднімання однієї секунди
	void showTime()const; //Демонстрація часу на екран з урахуванням встановленного формату

	//--------- Оператори порівняння (Comparison operators ) ---------
	bool operator == (const Time& obj)const&;
	bool operator != (const Time& obj)const&;
	bool operator > (const Time& obj)const&;
	bool operator < (const Time& obj)const&;
	bool operator >= (const Time& obj)const&;
	bool operator <= (const Time& obj)const&;

	//--------- Оператори присвоювання (Assignment operators) ---------	
	Time& operator += (float s);	// add seconds
	Time& operator -= (float s);
	Time& operator += (int m);	// add minutes
	Time& operator -= (int m);
	Time& operator += (long h);	// add hours
	Time& operator -= (long h);

	//--------- Арифметичні оператори (Arithmetic operators) ---------
	Time operator + (float s)const&;	// add seconds
	Time operator - (float s)const&;
	Time operator + (int m)const&; // add minutes
	Time operator - (int m)const&;
	Time operator + (long h)const&; // add hours
	Time operator - (long h)const&;

	Time& operator -- ();
	Time operator -- (int);
	Time& operator ++ ();
	Time operator ++ (int);

	friend std::ostream& operator << (std::ostream& out, const Time& obj);
};

