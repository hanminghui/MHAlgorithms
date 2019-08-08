/* 用一个字符串给定两个字符集合，用@分隔，
 * @前为全量字符集，@后为已占用字符集，
 * 要求输出剩余可用字符集
 */
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;

void ans(string);

int main(int argc, char *argv[])
{
	string input0 = "";
	string input1 = "a:1000,baby:6,car:4,d:5@a:1,baby:2,car:4";
	string input2 = "test:233@";
	string input3 = "@";
	string input4 = "a:3,b:5,c:2@a:1,b:2";

	std::cout << "0: ------------------------------" << std::endl;
	ans(input0);
	std::cout << "1: ------------------------------" << std::endl;
	ans(input1);
	std::cout << "2: ------------------------------" << std::endl;
	ans(input2);
	std::cout << "3: ------------------------------" << std::endl;
	ans(input3);
	std::cout << "4: ------------------------------" << std::endl;
	ans(input4);

    return 0;
}

void ans(string input)
{
	if(input.size() == 0 || input == "@")
	{
		std::cout << "" << std::endl;
		return;
	}
	map<string, int> result;
	string temp1, temp2;

	auto start = input.begin();
	int mode = 0;
	while(start != input.end())
	{
		if(*start == '@')
		{
			result.emplace(temp1, stoi(temp2));
			temp1.clear(); temp2.clear();
			mode = 0; // 换为字符模式
			start++; continue;
		}
		if(*start == ':')
		{
			mode = 1; // 换为数字模式
			start++; continue;
		}
		if(*start == ',')
		{
			auto temp1inresult = result.find(temp1);
			if(temp1inresult != result.end())
			{
				(*temp1inresult).second -= stoi(temp2);
			}
			else
			{
				result.emplace(temp1, stoi(temp2));
			}
			temp1.clear(); temp2.clear();
			mode = 0; // 换为字符模式
			start++; continue;
		}
		if(mode == 0) // 字符
		{
			temp1 += *start;
			start++; continue;
		}
		if(mode == 1) // 数字
		{
			temp2 += *start;
			start++; continue;
		}
	}
	if(!temp1.empty())
	{
		auto temp1inresult = result.find(temp1);
		if(temp1inresult != result.end())
		{
			(*temp1inresult).second -= stoi(temp2);
		}
		else
		{
			result.emplace(temp1, stoi(temp2));
		}
	}
	auto s = result.begin();
	for(; s != --result.end(); s++)
	{
		if(s->second != 0)
			std::cout << s->first << ":" << s->second << ",";
	}
	if(s->second != 0)
		std::cout << s->first << ":" << s->second << std::endl;
}
