#include <iostream>

int main(int argc, char *argv[])
{
    double bounce = 100;
	std::cout << "input times:" << std::endl;
	int times;
	std::cin >> times;
	double distance = 0;
	for(int i = 0; i < times; i++)
	{
		distance += bounce;
		bounce = bounce / 2;
		distance += bounce;
	}
	std::cout << distance << std::endl;
    return 0;
}
