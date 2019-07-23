#include <iostream>
#include <map>
#include <algorithm>
#include <utility>

typedef std::map<int, int> factors;

bool isPrime4(int n);
factors primeFactorization(int n);
void printFactor(std::pair<int, int> factor);

int main(int argc, char *argv[])
{
	factors f = primeFactorization(1233);
	std::for_each(f.begin(), --f.end(), printFactor);
	std::cout << f.rbegin()->first;
	if(f.rbegin()->second > 1)
		std::cout << "^" << f.rbegin()->second;
    return 0;
}

void printFactor(std::pair<int, int> factor)
{
    std::cout << factor.first;
	if(factor.second > 1)
		std::cout << "^" << factor.second;
	std::cout << " * ";
}

factors primeFactorization(int n)
{
	factors res;
	if(isPrime4(n))
		++res[n];
	else
	{
		while(!isPrime4(n))
		{
			for(int i = 2; i < n; i++)
			{
				if(isPrime4(i) && n % i == 0)
				{
					n /= i;
					++res[i];
					continue;
				}
			}
		}
		++res[n];
	}
	return res;
}

bool isPrime4(int n)
{
    if(n <= 3)
    {
        return n > 1;
    }
	if(n % 2 == 0 || n % 3 == 0)
	{
	    return false;
	}
	for(int i = 5; i * i <= n; i += 6)
	{
	    if(n % i == 0 || n % (i+2) == 0)
	    {
	        return false;
	    }
	}
	return true;
}
