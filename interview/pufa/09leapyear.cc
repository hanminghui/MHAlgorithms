#include <iostream>
bool isLeapyear(int year);

int main(int argc, char *argv[])
{
    for(int i = 1990; i <= 2019; i++)
	{
		if(isLeapyear(i))
			std::cout << i << std::endl;
	}
	std::cout << "1900: " << isLeapyear(1990) << std::endl;
    return 0;
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
