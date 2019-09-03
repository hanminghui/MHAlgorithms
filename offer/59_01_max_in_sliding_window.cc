#include <iostream>
#include <deque>
#include <vector>
#include <queue>

std::vector<int> maxInWindows(const std::vector<int> &nums, unsigned int size);

int main(int argc, char *argv[])
{
	std::vector<int> nums{2,3,4,2,6,2,5,1};
	std::vector<int> maxinwindow = maxInWindows(nums, 3);

	for(auto i : maxinwindow)
	{
	    std::cout << i << std::endl;
	}
    return 0;
}

/* size, the sliding window size */
std::vector<int> maxInWindows(const std::vector<int> &nums, unsigned int size)
{
	std::vector<int> maxs;
	if(nums.size() < size || size <= 0)
		return maxs;
	std::deque<int> index;
	for(int i = 0; i < size; i++)
	{
		while(!index.empty() && nums[index.back()] <= nums[i])
			index.pop_back();
		index.push_back(i);
	}
	for(int i = size-1; i < nums.size(); i++)
	{
		maxs.push_back(nums[index.front()]);
		while(!index.empty() && nums[i] >= nums[index.back()])
			index.pop_back();
		if(!index.empty() && index.front() <= (int)(i - size))
			index.pop_front();
		index.push_back(i);
	}
	maxs.push_back(nums[index.front()]);

	return maxs;
}
