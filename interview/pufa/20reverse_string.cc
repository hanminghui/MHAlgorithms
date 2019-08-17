#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string input;
	std::getline(std::cin, input);

	for(auto c = input.rbegin(); c != input.rend(); c++)
	{
		std::cout << *c;
	}
    return 0;
}
