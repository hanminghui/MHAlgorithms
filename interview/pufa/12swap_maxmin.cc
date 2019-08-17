#include <iostream>
using namespace std;
void swap(int nums[], int a, int b);

int main(int argc, char *argv[])
{
    int nums[10];
	for(int i = 0; i < 10; i++)
	{
		int temp;
		cin >> temp;
		nums[i] = temp;
	}
	int index_min = 0, index_max = 0;
	int n_min = nums[0], n_max = nums[0];
	for(int i = 0; i < 10; i++)
	{
		if(nums[i] < n_min)
		{
			n_min = nums[i];
			index_min = i;
		}
		if(nums[i] > n_max)
		{
			n_max = nums[i];
			index_max = i;
		}
	}
	swap(nums, 0, index_min);
	swap(nums, 9, index_max);

	for(int i = 0; i < 10; i++)
	{
		std::cout << nums[i] << ", ";
	}
	std::cout << std::endl;

    return 0;
}

void swap(int nums[], int a, int b)
{
	int temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}
