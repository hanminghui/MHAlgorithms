#include <iostream>
#include <string>

std::string ReverseSentence(std::string str);
void ReverseInString(std::string &str, int start, int end);

int main(int argc, char *argv[])
{
	std::string input;
	getline(std::cin, input);
	std::string revInput = ReverseSentence(input);
// 	ReverseInString(input, 0, input.size()-1);
// 	std::cout << input << std::endl;
	std::cout << revInput << std::endl;
    return 0;
}

std::string ReverseSentence(std::string str)
{
	if(str.empty())
		return str;
	ReverseInString(str, 0, str.size() - 1);
	int start = 0, end = 0;
	while(start < str.size()-1)
	{
		while(str[start] == ' ') {
			start++;
			end = start;
		}
		while(str[end] != ' ' && end < str.size())
		{
			end++;
		}
		if(end == str.size()-1)
			ReverseInString(str, start, end);
		else
			ReverseInString(str, start, end-1);
		start = end + 1;
		end = start;
	}
	return str;
}

void ReverseInString(std::string &str, int start, int end)
{
	while(start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
