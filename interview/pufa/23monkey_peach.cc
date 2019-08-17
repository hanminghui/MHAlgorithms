#include <iostream>

int main(int argc, char *argv[])
{
	int peaches[10];
	peaches[9] = 1;
	for(int i = 8; i >= 0; i--)
	{
		peaches[i] = (peaches[i+1] + 1) * 2;
	}
	for(int i = 0; i < 10; i++)
		std::cout << i+1 << ", "<< peaches[i] << std::endl;

    return 0;
}
