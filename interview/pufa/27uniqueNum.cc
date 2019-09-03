#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <map>

void uniqueNum(std::vector<int> &nums);
void uniqueNum1(std::vector<int> &nums);

int main(int argc, char *argv[])
{
	std::vector<int> nums = {1,2,3,4,5,6,4,5,4,6};
	std::cout << "nums: ";
	for(auto v : nums)
	{
	    std::cout << v << ", ";
	}
	std::cout << std::endl;
	uniqueNum(nums);
	std::cout << "-------------" << std::endl;
	uniqueNum1(nums);
    return 0;
}

void uniqueNum(std::vector<int> &nums)
{
	std::unordered_set<int> uniqs;
	for(int i = 0; i < nums.size(); i++)
	{
		uniqs.insert(nums[i]);
	}
	for(auto e : uniqs)
	{
	    std::cout << e << std::endl;
	}
}

void uniqueNum1(std::vector<int> &nums)
{
	std::map<int, int> ct_nums;
	for(auto i : nums)
	{
		auto f = ct_nums.find(i);
	    if(f == ct_nums.end())
		{
			ct_nums[i] = 1;
		}
		else
		{
			f->second += 1;
		}
	}
	for(auto e : ct_nums)
	{
		if(e.second == 1)
			std::cout << e.first << std::endl;
	}
}
