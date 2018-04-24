#include <iostream>

using namespace std;

bool IsLeapYear1 (int year);
bool IsLeapYear2 (int year);
bool IsBigMonth (int month);
int DaysInMonth (int year, int month);

int main ()
{
	int year, month, daysInMonth;
	bool isBigMonth, isLeapYear;
	while (true)
	{
		cin >> year >> month;
		isLeapYear = IsLeapYear1(year);
		isBigMonth = IsBigMonth(month);
		daysInMonth = DaysInMonth(year, month);
		if (IsLeapYear1(year))
			cout << "It's a leap year." << endl;
		else
			cout << "It's a common year." << endl;
		if (IsBigMonth(month))
			cout << "Month " << month << " is big month, ";
		else
			cout << "Month " << month << " is small month, ";

			cout << "it has " << daysInMonth << " days." << endl;
	}
	return 0;
}

bool IsLeapYear1 (int year)
{
	if ( (year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0) )
		return true;
	else
		return false;
}

bool IsLeapYear2 (int year)
{
	if ( year % 4 != 0 )
		return false;		// common year
	else if ( year % 100 != 0 )
		return true;		// leap year
	else if ( year % 400 != 0 )
		return false;		// common year
	else
		return true;
}

bool IsBigMonth (int month)
{
	int bigMonth[7] = {1,3,5,7,8,10,12};
	for (int i = 0; i < 7; i++)
	{
		if (month == bigMonth[i])
			return true;
	}
	return false;
}

int DaysInMonth (int year, int month)
{
	int leapYear[12] = {31,29,31,30,31, 30,31,31,30,31, 30,31};
	int commonYear[12] = {31,28,31,30,31, 30,31,31,30,31, 30,31};
	if (IsLeapYear1(year))
		return leapYear[month-1];
	else
		return commonYear[month-1];
}
