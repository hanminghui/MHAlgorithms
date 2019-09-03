#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> FindNumbersWithSum0(vector<int> array, int sum);
vector<int> FindNumbersWithSum1(vector<int> array, int sum);

int main(int argc, char *argv[])
{
	vector<int> input{1,2,4,7,11,15};
	for(auto n : input)
		cout << n << " ";
	cout << endl;
	int sum = 15;
	vector<int> result = FindNumbersWithSum1(input, sum);
	std::cout << "nums with sum " << sum << ":" << std::endl;
	for(auto n : result)
		cout << n << " ";
	cout << endl;
    return 0;
}

vector<int> FindNumbersWithSum0(vector<int> array, int sum)
{
	vector<int> result;
	for(auto n : array)
	{
		if(std::binary_search(array.begin(), array.end(), sum-n))
		{
			result.push_back(n);
			result.push_back(sum-n);
			break;
		}
	}
	return result;
}

vector<int> FindNumbersWithSum1(vector<int> array, int sum)
{
	vector<int> result;
	if(array.empty()) return result;
	auto start = array.begin();
	auto last = array.end()-1;
	while(start < last)
	{
		if(*start + *last == sum)
		{
			result.push_back(*start);
			result.push_back(*last);
			break;
		}
		if(*start + *last > sum)
		{
			last--;
		}
		if(*start + *last < sum)
		{
			start++;
		}
	}
	return result;
}
