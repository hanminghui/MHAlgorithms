#include <iostream>
#include <array>

using namespace std;

array<int,100> lookup;

int fibonacci(int n)
{
	if(lookup[n] == -1)
	{
		if(n < 2)
			lookup[n] = n;
		else
			lookup[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
	return lookup[n];
}


int main(int argc, char *argv[])
{
	lookup.fill(-1);
	cout << fibonacci(9) << endl;

    return 0;
}
