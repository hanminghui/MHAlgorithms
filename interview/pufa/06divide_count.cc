#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n, b;
	cin >> n >> b;

	int ct = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i % b == 0)
			ct++;
	}
	std::cout << ct << std::endl;
    return 0;
}
