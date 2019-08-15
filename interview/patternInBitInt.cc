/* find a pattern '101'
 * in a bit representation of a int
 * input: a int
 * output: firstline, first occurence
 *         secondline, number of occurence
 */
#include <iostream>
#include <bitset>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	int input;
    cin >> input;

	string s = bitset<64>(input).to_string();
	string a;

	auto firstone = s.find('1');
	if(firstone == string::npos)
	{
		std::cout << 0 << std::endl;
		std::cout << 0 << std::endl;
		return 0;
	}
	a = s.substr(firstone, s.length()-firstone);
	std::cout << a << std::endl;

	int start = 0;
	int first101 = 0;
	int findfirst = 0;
	int num = 0;
	while(start <= a.length() - 3)
	{
		string b = a.substr(start, 3);
		if(b == "101" && findfirst == 0)
		{
			first101 = start;
			findfirst = 1;
		}
		if(b == "101")
		{
			num++;
		}
		start++;
	}

	std::cout << std::endl;
	std::cout << num << std::endl;
	std::cout << first101 << std::endl;
    return 0;
}
