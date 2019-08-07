#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	map<char, int> all;
	map<char, int> part;

	string input = "a:2,b:6,c:4@a:1,b:2";
	auto at_sign = find(input.begin(), input.end(), '@');
	string strall, strpart;
	copy(input.begin(), at_sign, back_inserter(strall));
	copy(at_sign+1, input.end(), back_inserter(strpart));

	int pos = 0;
	while(pos + 3 <= strall.size())
	{
		all.emplace(strall[pos], strall[pos+2]);
		pos += 4;
	}
	pos = 0;
	while(pos + 3 <= strall.size())
	{
		part.emplace(strpart[pos], strpart[pos+2]);
		pos += 4;
	}

	string result;
	for(auto s : all)
	{
		if(part.find(s.first) != part.end())
		{
			auto b = (*(part.find(s.first))).second;
			int c = s.second - b;
			if(c == 0)
			{}
			else
			{
			result += s.first;
			result += ':';
			result += to_string(c);
			result += ',';
			}
		}
		else
		{
			result += s.first;
			result += ':';
			result += s.second;
			result += ',';
		}
	}
	if(!result.empty())
	{
		result.pop_back();
	}
	std::cout << result << std::endl;

    return 0;
}
