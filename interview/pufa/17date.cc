#include <iostream>

int nthday(int year, int month, int day);
bool isLeapyear(int year);

int main(int argc, char *argv[])
{
    int year, month, day;
	std::cin >> year >> month >> day;
	std::cout << nthday(year, month, day) << std::endl;
    return 0;
}

int nthday(int year, int month, int day)
{
	int n = 0;
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if(isLeapyear(year))
		days[1] = 29;
	for(int i = 0; i < month - 1; i++)
	{
		n += days[i];
	}
	return n + day;
}

bool isLeapyear(int year)
{
	if(year % 100 == 0)
	{
		if(year % 400 == 0)
			return true;
	}
	else if(year % 4 == 0)
	{
	    return true;
	}
	return false;
}
