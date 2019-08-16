#include <iostream>
#include <bitset>
#include <string>

int ones(int num);

int main(int argc, char *argv[])
{
	int input;
	std::cout << "input a int" << std::endl;
	std::cin >> input;
	std::bitset<sizeof(int)*8> bit(input);
	std::cout << bit << std::endl;
	std::string bitstr = bit.to_string();
	int ones_count = 0;
	auto ch = bitstr.begin();
	while(ch != bitstr.end())
	{
		if(*ch == '1')
		{
			ones_count++;
		}
		ch++;
	}
	std::cout << "number of one: " << ones_count << std::endl;
	/* another method */
	std::cout << "number of one: " << ones(input) << std::endl;
	return 0;
}

int ones(int num)
{
	unsigned n = (unsigned)num;
	int ones_count = 0;
	while(n != 0)
	{
		if((n & 1) == 1)
		{
		    ones_count++;
		}
		n = n >> 1;
	}
	return ones_count;
}
