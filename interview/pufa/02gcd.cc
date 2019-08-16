#include <iostream>

using namespace std;

int gcd(int a, int b);

int main(int argc, char *argv[])
{
	cout << "input 2 nums:" << endl;
	int a, b;
	cin >> a >> b;
	cout << "the gcd of the 2 num is " << gcd(a,b) << endl;
}

int gcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	else return gcd(b, a % b);
}
