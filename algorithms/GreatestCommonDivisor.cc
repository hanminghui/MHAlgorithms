// --------------------------------------------------
// Greatest/Highest Common Divisor/Factor/Measure
// gcd / gcf / gcm / hcf / hcd

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <cmath>


typedef std::vector<int> ints;
typedef std::map<int, int> factors;

int GCD0(int a, int b);
int GCD1(int a, int b);
int GCD2(int a, int b);
int GCD_vector(ints n);
bool isPrime4(int n);
factors primeFactorization(int n);

ints& divisors(int n);

int main(int argc, char *argv[])
{
	for(auto x : divisors(24))
	{
		std::cout << x << ", ";
	}
	std::cout << std::endl;

	std::cout << "GCD0: " << GCD0(252,105) << std::endl;
	std::cout << "GCD1: " << GCD1(252,105) << std::endl;
	std::cout << "GCD2: " << GCD2(252,105) << std::endl;

	ints numbers{2,4,6,8,16};
	std::cout << "GCD of vectors: " <<  GCD_vector(numbers) << std::endl;

    return 0;
}

// ==================================================
// ┌────────────────────────────────────────────────┐
// │                       GCD                      │
// └────────────────────────────────────────────────┘

// ---------------------- GCD0 ----------------------
// use prime factorization
int GCD0(int a, int b)
{
	factors factors_a = primeFactorization(a);
	factors factors_b = primeFactorization(b);
	auto iter_a = factors_a.begin();
	auto iter_b = factors_b.begin();
	int result = 1;
	while(iter_a != factors_a.end() && iter_b != factors_b.end())
	{
		if(iter_a->first < iter_b->first)
			++iter_a;
		if(iter_a->first > iter_b->first)
			++iter_b;
		if(iter_a->first == iter_b->first)
		{
			result *= pow(iter_a->first, 
					iter_a->second <= iter_b->second ? iter_a->second : iter_b->second);
			++iter_a;
			++iter_b;
		}
	}
	return result;
}

// ---------------------- GCD1 ----------------------
// use Euclidean algorithm

int GCD1(int a, int b)
{
    if(a == 0 || b == 0)
    {
        return 0;
    }
	if(a == b)
	{
	    return a;
	}
	if(a < b)
	{
		return GCD1(a, b - a);
	}
	return GCD1(a - b, b);
}

// ---------------------- GCD2 ----------------------
// replace - with %
int GCD2(int a, int b)
{
	if(b == 0)
	{
	    return a;
	}
	return GCD2(b, a % b);
}

// ------------------- GCD_vector -------------------

int GCD_vector(ints n)
{
	if(n.size() == 2)
	{
	    return GCD2(n[0], n[1]);
	}
	int temp = *n.rbegin();
	n.pop_back();
    return GCD2(GCD_vector(n), temp);
}

// ==================================================
// ┌────────────────────────────────────────────────┐
// │              divisors of a number              │
// └────────────────────────────────────────────────┘

ints& divisors(int n)
{
	static ints d;
	for(int i = 1; i <= n; i++)
	{
		if(n % i == 0)
		{
			d.push_back(i);
		}
	}
	return d;
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
