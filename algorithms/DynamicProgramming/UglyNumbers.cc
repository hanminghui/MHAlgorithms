#include <iostream>
#include <algorithm>
#include <vector>

int nUgly0(int n);
int nUgly1(int n);
bool isUgly(int n);

int main(int argc, char *argv[])
{
	std::cout << "Input a number k, and get the k-th Ugly number:" << std::endl;
	int k;
	std::cin >> k;
	std::cout << "the " << k << "-th Ugly: " << nUgly1(k) << std::endl;
    return 0;
}

int nUgly1(int n)
{
	std::vector<int> uglys;
	int i = 1;
	uglys.push_back(i);
	int M2 = 0, M3 = 0, M5 = 0;
	int m = 0;
	while(i < n)
	{
		m = std::min(std::min(uglys[M2]*2, uglys[M3]*3), uglys[M5]*5);
		uglys.push_back(m);
		while(uglys[M2]*2 <= m)
		{
		    M2++;
		}
		while(uglys[M3]*3 <= m)
		{
		    M3++;
		}
		while(uglys[M5]*5 <= m)
		{
		    M5++;
		}
		i++;
	}
	int result = *uglys.rbegin();
	return result;
}

int nUgly0(int n)
{
	int result = 1;
	int k = 1;
	while(k != n)
	{
		++result;
		if(isUgly(result))
		{
			++k;
		}
	}
	return result;
}

bool isUgly(int n)
{
	while(n % 2 == 0)
	{
		n /= 2;
	}
	while(n % 3 == 0)
	{
		n /= 3;
	}
	while(n % 5 == 0)
	{
		n /= 5;
	}
	return n == 1;
}
