#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

template<typename Function>
void testFunction(Function func);
void printPrime(bool (*prime)(int), int n);
bool isPrime0(int n);
bool isPrime1(int n);
bool isPrime2(int n);
bool isPrime3(int n);
bool isPrime4(int n);
int kPrime(bool (*isPrime)(int n), int n);
int primorial_n(bool (*isPrime)(int n), int n);
int primorial_Pn(bool (*isPrime)(int n), int c);

int main(int argc, char *argv[])
{
// 	testFunction(isPrime0);
// 	testFunction(isPrime1);
// 	testFunction(isPrime2);
// 	testFunction(isPrime3);
// 	testFunction(isPrime4);
// 	printPrime(isPrime4, 100);
	int n = 11;
	cout << "integer n     : " << n << endl;
	cout << "k_th prime(Pn): " << kPrime(isPrime4, n) << endl;
	cout << "primorial(n#) : " << primorial_n(isPrime4, n) << endl;
	cout << "primorial(Pn#): " << primorial_Pn(isPrime4, n) << endl;
    return 0;
}

template<typename Function>
void testFunction(Function func)
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for(int i = 0; i < 100; i++)
	{
		for(int i = 0; i < 10000; i++)
		{
			func(i);
		}
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(t2 - t1).count();

	cout << duration << endl;
}

void printPrime(bool (*prime)(int), int n)
{
	for(int i = 0; i < n; i++)
	{
		if(prime(i))
			cout << i << ", ";
	}
	cout << endl;
}

// ==================================================
// ┌────────────────────────────────────────────────┐
// │                     isPrime                    │
// └────────────────────────────────────────────────┘

// ==================== isPrime0 ====================
bool isPrime0(int n)
{
	if(n <= 1)
		return false;
	// iterate from 2 to n
	for(int i = 2; i < n; i++)
	{
		// if n is divisible by any number between 2 and n,
		// it is not prime
		if(n % i == 0)
			return false;
	}
	return true;
}

// ==================== isPrime1 ====================
bool isPrime1(int n)
{
	if(n <= 1)
		return false;
	// iterate from 2 to n/2
	for(int i = 2; i <= n/2; i++)
	{
		// if n is divisible by any number between 2 and n/2,
		// it is not prime
		if(n % i == 0)
			return false;
	}
	return true;
}

// ==================== isPrime2 ====================
bool isPrime2(int n)
{
	if(n <= 1)
		return false;
	// iterate from 2 to sqrt(2)
	for(int i = 2; i * i <= n; i++)
	{
		// if n is divisible by any number between 2 and sqrt(2),
		// it is not prime
		if(n % i == 0)
			return false;
	}
	return true;
}

// ==================== isPrime3 ====================
bool isPrime3(int n)
{
	if(n <= 3)
		return n > 1;
	// if n is divisible by an even, it is not prime
	if(n % 2 == 0)
		return false;
	// iterate from 3 to sqrt(2), jump even numbers
	for(int i = 3; i * i <= n; i += 2)
	{
		// if n is divisible by any odd number between 3 and sqrt(2),
		// it is not prime
		if(n % i == 0)
			return false;
	}
	return true;
}

// ==================== isPrime4 ====================
// all primes are of the form 6k+-1, except 2 and 3
bool isPrime4(int n)
{
	if(n <= 3)
		return n > 1;
	if(n % 2 == 0 || n % 3 == 0)
		return false;
	for(int i = 5; i * i <= n; i += 6)
	{
		if(n % i == 0 || n % (i+2) == 0)
			return false;
	}
	return true;
}

// ==================================================
// ┌────────────────────────────────────────────────┐
// │                   K_th Prime                   │
// └────────────────────────────────────────────────┘

int kPrime(bool (*isPrime)(int n), int n)
{
	int k = 0;
	int k_prime = 0;
	while(k < n)
	{
		++k_prime;
		if(isPrime(k_prime))
			++k;
	}
	return k_prime;
}

// ==================================================
// ┌────────────────────────────────────────────────┐
// │                    Primorial                   │
// └────────────────────────────────────────────────┘
// There are two different definition of Primorial:
// reference: wikipedia-Primorial

// n#
// return the result of successively multipy prime numbers smaller than n
int primorial_n(bool (*isPrime)(int n), int n)
{
	int k = 0;
	int res = 1;
	while(k < n)
	{
		++k;
		if(isPrime(k))
		{
			res *= k;
		}
	}
	return res;
}

// Pn#
// return the successively multipy result of first n prime numbers
int primorial_Pn(bool (*isPrime)(int n), int c)
{
	int k = 0;
	int k_prime = 0;
	int res = 1;
	while(k < c)
	{
		++k_prime;
		if(isPrime(k_prime))
		{
			res *= k_prime;
			++k;
		}
	}
	return res;
}
