#include <iostream>

int sumDigit(int num)
{
	int sum = 0;
	while(num)
	{
		sum += num % 10;
		num = num / 10;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int n;
	std::cin >> n;
	std::cout << sumDigit(n) << std::endl;
    return 0;
}
