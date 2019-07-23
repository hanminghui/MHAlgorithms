// compile commands as follows:
// g++ PrimeBig.cc -lgmpxx -lgmp -o PrimeBig
#include <iostream>
#include <chrono>
#include <gmpxx.h>

using namespace std;

bool isPrime4_big(mpz_class n);
mpz_class kPrime(bool (*isPrime)(mpz_class n), int n);
mpz_class primorial_n(bool (*isPrime)(mpz_class n), int n);
mpz_class primorial_Pn(bool (*isPrime)(mpz_class n), int c);

int main(int argc, char *argv[])
{
	int n = 40;
	cout << "integer n     : " << n << endl;
	cout << "k_th prime(Pn): " << kPrime(isPrime4_big, n) << endl;
	cout << "primorial(n#) : " << primorial_n(isPrime4_big, n) << endl;
	cout << "primorial(Pn#): " << primorial_Pn(isPrime4_big, n) << endl;
    return 0;
}

// ==================================================
// ┌────────────────────────────────────────────────┐
// │                     isPrime                    │
// └────────────────────────────────────────────────┘

// ================== isPrime4_big ==================
// all primes are of the form 6k+-1, except 2 and 3
bool isPrime4_big(mpz_class n)
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

mpz_class kPrime(bool (*isPrime)(mpz_class n), int n)
{
	int k = 0;
	mpz_class k_prime("0");
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
mpz_class primorial_n(bool (*isPrime)(mpz_class n), int n)
{
	int k = 0;
	mpz_class res("1");
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
mpz_class primorial_Pn(bool (*isPrime)(mpz_class n), int c)
{
	int k = 0;
	int k_prime = 0;
	mpz_class res("1");
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
