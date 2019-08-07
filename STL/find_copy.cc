#include <algorithm>
#include <iostream>
#include <vector>

void printvec(std::vector<int>);

int main(int argc, char *argv[])
{
    std::vector<int> origins;
	for(int i = 0; i < 10; i++)
	{
	    origins.push_back(i+1);
	}
	printvec(origins);
	auto result = std::find(origins.begin(), origins.end(), 5);
	std::cout << *result << std::endl;
	std::vector<int> left;
	std::copy(origins.begin(), result, std::back_inserter(left));
	printvec(left);
	
    return 0;
}

void printvec(std::vector<int> vec)
{
	for(auto n : vec)
	{
		std::cout << n << ",";
	}
	std::cout << std::endl;
}
