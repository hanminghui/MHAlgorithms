#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string input;
	std::getline(std::cin, input);

	for(size_t i = 0; i < input.size(); i++)
	{
		if(input[i] >= 'a' && input[i] <= 'z')
		{
			input[i] += 'A' - 'a';
		}
		else if(input[i] >= 'A' && input[i] <= 'Z')
		{
			input[i] -= 'A' - 'a';
		}
	}
	std::cout << input << std::endl;
    return 0;
}
