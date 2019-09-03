#include <iostream>

bool isSquare(int n);
bool isSquare1(int n);

int main(int argc, char *argv[])
{
    std::cout << "input an int:" << std::endl;
	int input;
	std::cin >> input;
	if(isSquare(input))
	{
		std::cout << "TRUE" << std::endl;
	}
	else
	{
	    std::cout << "FALSE" << std::endl;
	}
    return 0;
}

bool isSquare(int n)
{
	if(n <= 0) return false;
	for(int i = 1; n > 0; i += 2)
	{
		n -= i;
	}
    return 0 == n;
}

bool isSquare1(int n)
{
    for(int i = 1; i * i <= n; i++)
	{
		if(i * i == n)
			return true;
	}
	return false;
}
