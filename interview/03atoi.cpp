#include <iostream>
#include <string>

using namespace std;

int myatoi (char * integer);

int main ()
{
	char * s = "12345";
	int intS = atoi(s);
	cout << intS << endl;
	return 0;
}

int myatoi (char * integer)
{
	int num = 0;
	while(*integer >= '0' && *integer <= '9')
	{
		num = num * 10 + *integer - '0';
		integer++;
	}
	return num;
}
