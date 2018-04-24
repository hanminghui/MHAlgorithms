#include <iostream>

using namespace std;

int ZeroInInteger1 (int num);	// Recursion
int ZeroInInteger2 (int num);	// Iteration

int main()
{
	int num;
	cin >> num;
	if (ZeroInInteger1(num) > 1)
		cout << ZeroInInteger1(num) << " Zeros in it." << endl;
	else
		cout << ZeroInInteger1(num) << " Zero in it." << endl;
	return 0;
}

int ZeroInInteger1 (int num)	// Recursion
{
	int count;
	if (num == 0)
		return 1;
	else if (num < 10)
		return 0;
	else if (num % 10 == 0)
		return ZeroInInteger1(num / 10) + 1;
	else
		return ZeroInInteger1(num / 10);
}

int ZeroInInteger2 (int num)	// Iteration
{
	int count = 0;
	if (num == 0)
		return 1;
	while (num >= 10)
	{
		if (num % 10 == 0)
			count++;
		num /= 10;
	}
	return count;
}

