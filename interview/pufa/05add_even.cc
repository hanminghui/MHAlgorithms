#include <iostream>
void add_even(int num);

int main(int argc, char *argv[])
{
    std::cout << "input an int:" << std::endl;
	int input;
	std::cin >> input;

	add_even(input);
    return 0;
}

void add_even(int num)
{
    int ct_even = 0;
	while(num > 0)
	{
		int temp = num % 10;
		if(temp % 2 == 0)
		{
		    ct_even += temp;
		}
		num /= 10;
	}
	std::cout << ct_even << std::endl;
}
