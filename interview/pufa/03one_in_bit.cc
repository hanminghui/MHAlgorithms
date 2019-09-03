#include <iostream>
#include <bitset>
#include <string>

int ones0(int num);
int ones1(int num);
int ones2(int num);

int main(int argc, char *argv[])
{
	int input;
	std::cout << "input a int" << std::endl;
	std::cin >> input;
	std::bitset<sizeof(int)*8> bit(input);
	std::cout << bit << std::endl;

	/* method 1 */
	std::cout << "-----" << std::endl;
	std::cout << "number of one: " << bit.count() << std::endl;
	/* method 2 */
	std::cout << "-----" << std::endl;
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
	/* method 3 */
	std::cout << "-----" << std::endl;
	std::cout << "number of one: " << ones0(input) << std::endl;
	/* method 4 */
	std::cout << "-----" << std::endl;
	std::cout << "number of one: " << ones1(input) << std::endl;
	/* method 5 */
	std::cout << "-----" << std::endl;
	std::cout << "number of one: " << ones2(input) << std::endl;
	return 0;
}

/* right shift the num */
int ones0(int num)
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

/* left shift 1 */
int ones1(int num)
{
	int count = 0;
	unsigned int flag = 1;
	while(flag)
	{
		if(num & flag)
		{
		    count++;
		}
		flag <<= 1;
	}
	return count;
}

/* int & (int - 1)
 * will remove the last 1 in bit */
int ones2(int num)
{
	int count = 0;
	while(num)
	{
		num = num & (num - 1);
		count++;
	}
	return count;
}
