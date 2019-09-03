#include <iostream>

int main(int argc, char *argv[])
{
    std::string input = "abc b    ";

	std::cout << input << "." << std::endl;

	auto last = input.rbegin();
	while(*last == ' ')
	{
		input.pop_back();
		last++;
	}
	std::cout << input << "." << std::endl;
    return 0;
}
