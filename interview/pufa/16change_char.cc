#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string input;
	std::getline(std::cin, input);
	for(int i = 0; i < input.size(); i++)
	{
	    if(input[i] == 'a' || input[i] == 'A')
	    {
	        std::cout << 'c';
	    }
		else
		{
			std::cout << input[i];
		}
	}
	std::cout << std::endl;
    return 0;
}
