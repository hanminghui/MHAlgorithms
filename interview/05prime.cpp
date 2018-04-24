#include <iostream>

using namespace std;

bool isPrime1 (int num);
bool isPrime2 (int num);

int main ()
{
	int input;
	int count = 0;
	cout << "Enter an integer:" << endl;
	cin >> input;
	cout << endl;
	for(int i = 2; i <= input; i++)
	{
		if(isPrime2(i))
		{
			cout << i << " ";
			count++;
		}
	}
	cout << "\nThere are " << count << " primes." << endl;
	return 0;
}

bool isPrime1 (int num)
{
	if (num == 2)
		return true;
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

bool isPrime2 (int num)
{
	if (num <= 3)
		return num > 1;
	else if (num % 2 == 0 || num % 3 == 0)
		return false;
	else
	{
		for (int i = 5; i*i <= num; i += 6)
		{
			if (num % i == 0 || num % (i+2) == 0)
				return false;
		}
		return true;
	}
}
