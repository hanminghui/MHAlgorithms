#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
	cin >> n;

	int factorial = 1;
	for(int i = 1; i <= n; i++)
	{
		factorial *= i;
	}
	std::cout << factorial << std::endl;
    return 0;
}
