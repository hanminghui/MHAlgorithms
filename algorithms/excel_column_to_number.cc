/* Excel column letter to number
 * and
 * number to Excel column letter
 */

#include <iostream>
#include <string>
#include <cctype>
#include <stack>
int ExcelToN(std::string &s);
std::string NToExcel(int n);
int ProcessInput(std::string &s);

int main(int argc, char *argv[])
{
	std::cout << "Convert: Excel column letter & Number" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "input what you what to convert:" << std::endl;
	std::string s;
	std::cin >> s;
	switch(ProcessInput(s))
	{
		case 1: {
			std::cout << "Excel : " << s << std::endl;
			std::cout << "to N : " << ExcelToN(s) << std::endl;
			break;
		}
		case 2: {
			int n = stoi(s);
			std::cout << "N : " << n << std::endl;
			std::cout << "to excel : " << NToExcel(n) << std::endl;
			break;
		}
		default:
			std::cout << "input error, number or excel column letter" << std::endl;
	}
    return 0;
}

int ExcelToN(std::string &s)
{
	int n = 0;
	auto start = s.begin();
	while(start != s.end())
	{
		n *= 26;
		n += std::tolower(*start) - 'a' + 1;
		start++;
	}
	return n;
}

std::string NToExcel(int n)
{
    std::string s;
	std::stack<char> cs;
	while(n)
	{
		if(n % 26)
		{
			cs.push('A' + n % 26 - 1);
		}
		else
		{
			cs.push('Z');
			n -= 26;
		}
		n /= 26;
	}
	while(!cs.empty())
	{
		s += cs.top();
		cs.pop();
	}
	return s;
}

int ProcessInput(std::string &s)
{
    int r = 0;
	auto start = s.begin();
	if(std::isalpha(*start))
	{
		while(start != s.end())
		{
			if(!std::isalpha(*start))
				return 0;
			start++;
		}
		return 1;
	}
	if(std::isdigit(*start))
	{
		while(start != s.end())
		{
			if(!std::isdigit(*start))
				return 0;
			start++;
		}
		return 2;
	}
	return r;
}
