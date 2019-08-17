#include <iostream>

using namespace std;
bool isPrime(int n);

int main(int argc, char *argv[])
{
	for(int i = 1; i < 100; i++)
	{
		if(isPrime(i))
			std::cout << i << ", ";
	}
	std::cout << std::endl;
    return 0;
}

bool isPrime(int n)
{
	if(n > 0 && n < 4)
		return true;
	int i = 2;
	while(i * i <= n)
	{
		if(n % i == 0)
			return false;
		i++;
	}
	return true;
}
