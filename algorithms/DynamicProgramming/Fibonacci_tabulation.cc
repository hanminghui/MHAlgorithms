#include <iostream>
#include <array>

using namespace std;

array<int,100> lookup;

int fibonacci(int n)
{
	lookup[0] = 0;
	lookup[1] = 1;
	for(int i = 2; i < 100; i++)
	{
		lookup[i] = lookup[i-1] + lookup[i-2];
	}
	return lookup[n];
}

int main(int argc, char *argv[])
{
	lookup.fill(-1);
	cout << fibonacci(9) << endl;

    return 0;
}
