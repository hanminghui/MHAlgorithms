#include <iostream>

int StrToInt0(const char *);
bool StrToInt1(const char * in, int& out);

int main()
{
	std::string input;
	int num;
	std::cout << "Please input a number: " << std::endl;
	std::cin >> input;
	const char * in = input.c_str();
	if(StrToInt1(in, num))
	{
		std::cout << "What you input plus 1 is: " << num + 1 << std::endl;
	}

	// nullptr test
	char * test = nullptr;
	StrToInt1(test, num);
	return 0;
}

int StrToInt0(const char * in)
{
	int num = 0;
	while(*in)
	{
		num = num * 10 + *in - '0';
		++in;
	}
	return num;
}

bool StrToInt1(const char * in, int& out)
{
	if(!in)
	{
		std::cout << "nullptr!!!" << std::endl;
		return false;
	}
	if(*in > '9' || *in < '0')
	{
		std::cout << "not an integer" << std::endl;
		return false;
	}
	if(*in == '+' || *in == '-')
	{
		std::cout << "nullptr!!!" << std::endl;
	}
	out = 0;
	while(*in)
	{
		out = out * 10 + *in - '0';
		++in;
	}
	return true;
}
