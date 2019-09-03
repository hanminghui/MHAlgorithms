/* input: an int array
 * move all odd numbers before even
 */

#include <bits/stdc++.h>
using namespace std;

void reOrderArray0(vector<int> &nums);
void reOrderArray1(vector<int> &nums);

int main(int argc, char *argv[])
{
	vector<int> nums{1,2,3,4,5,6,7,8};
	cout << "original:" << endl;
	for(auto n : nums)
		cout << n << " ";
	cout << endl;
	reOrderArray0(nums);
	cout << "reorder:" << endl;
	for(auto n : nums)
		cout << n << " ";
	cout << endl;
	vector<int> nums1{1,2,3,4,5,6,7,8};
	reOrderArray1(nums1);
	cout << "reorder:" << endl;
	for(auto n : nums1)
		cout << n << " ";
	cout << endl;
    return 0;
}

/* the order in odd or even nums change */
void reOrderArray0(vector<int> &nums)
{
	int start = 0, end = nums.size() -1;
	while(start < end)
	{
		while(nums[start] % 2 != 0)
			++start;
		while(nums[end] % 2 == 0)
			--end;
		if(start < end)
		{
			int temp = nums[start];
			nums[start] = nums[end];
			nums[end] = temp;
		}
	}
}

/* keep the order */
void reOrderArray1(vector<int> &nums)
{
	vector<int> temp;
	queue<int> q;
	for(auto n : nums)
	{
		if(n % 2 != 0)
			temp.push_back(n);
		else
			q.push(n);
	}
	while(!q.empty())
	{
		temp.push_back(q.front());
		q.pop();
	}
	nums.clear();
	for(auto n : temp)
	{
		nums.push_back(n);
	}
}
