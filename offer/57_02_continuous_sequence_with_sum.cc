#include <iostream>

void FindContinuousSequence(int);

int main(int argc, char *argv[])
{
    std::cout << "input a sum:" << std::endl;
	int sum = 0;
	std::cin >> sum;
	FindContinuousSequence(sum);

    return 0;
}

void FindContinuousSequence(int s)
{
	if(s < 3)
		return;
	int small = 1, big = 2, sum = 3;
	while(small < s / 2 + 1)
	{
		while(sum < s)
		{
			big++;
			sum += big;
		}
		if(sum == s)
		{
			for(int i = small; i <= big; i++)
				std::cout << i << " ";
			std::cout << std::endl;
		}
		sum -= small;
		small++;
	}
}
