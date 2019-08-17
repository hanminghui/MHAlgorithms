#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string input;
	std::getline(std::cin, input);
	std::string abbr;

	bool inword = false;
	for(size_t i = 0; i < input.size(); i++)
	{
		if(!inword)
		{
			if(input[i] >= 'a' && input[i] <= 'z')
			{
				abbr += input[i] + 'A' - 'a';
				inword = true;
			}
			else if(input[i] >= 'A' && input[i] <= 'z')
			{
				abbr += input[i];
				inword = true;
			}
		}
		if(input[i] == ' ')
			inword = false;
	}
	std::cout << abbr << std::endl;
    return 0;
}
