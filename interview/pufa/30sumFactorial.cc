#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
	cin >> n;

	int sum = 0;
	int factorial = 1;
	for(int i = 1; i <= n; i++)
	{
		factorial *= i;
		sum += factorial;
	}
	std::cout << sum << std::endl;
    return 0;
}
