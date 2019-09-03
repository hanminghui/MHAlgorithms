#include <iostream>

int fibonacci_recursive(int n);
int fibonacci_iterative(int n);

int main(int argc, char *argv[])
{
	std::cout << fibonacci_iterative(40) << std::endl;
	std::cout << fibonacci_recursive(40) << std::endl;
    return 0;
}

int fibonacci_recursive(int n)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

int fibonacci_iterative(int n)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
	int f2 = 0, f1 = 1, f = 3;
	for(int i = 2; i <= n; i++)
	{
		f = f2 + f1;
		f2 = f1;
		f1 = f;
	}
	return f;
}
