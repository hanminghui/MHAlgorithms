#include <iostream>
#include <string>

void ReverseInString(std::string &str, int start, int end);
void LeftRotate(std::string &str, int num);

int main(int argc, char *argv[])
{
	std::cout << "input a string:" << std::endl;
	std::string input;
	getline(std::cin, input);
	std::cout << "input num to left rotate:" << std::endl;
	int num;
	std::cin >> num;
	LeftRotate(input, num);
	std::cout << input << std::endl;
    return 0;
}

void LeftRotate(std::string &str, int num)
{
	if(str.empty() || num >= str.size() || num <= 0)
		return;
	int start = 0, end = str.size()-1;
	ReverseInString(str, start, end);
	ReverseInString(str, start, str.size()-num-1);
	ReverseInString(str, str.size()-num, end);
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
