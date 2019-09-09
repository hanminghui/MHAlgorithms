#include <bits/stdc++.h>
using namespace std;

void MoveInNeibor(vector<vector<int>> &matrix,
		          vector<int> &nums, 
				  vector<vector<int>> &visited,
				  int x, int y, int &steps)
{
	if(x < 0 || y < 0 || x > 4 || y > 4 || visited[x][y])
		return;
	if(find(nums.begin(), nums.end(), matrix[x][y]) == nums.end())
	{
		std::cout << "notfind" << std::endl;
		return;
	}
	steps++;
	std::cout << "steps= " << steps << std::endl;
	visited[x][y] = 1;
	MoveInNeibor(matrix, nums, visited, x-1, y, steps);
	MoveInNeibor(matrix, nums, visited, x+1, y, steps);
	MoveInNeibor(matrix, nums, visited, x, y-1, steps);
	MoveInNeibor(matrix, nums, visited, x, y+1, steps);
}

int IsNeighbor(vector<vector<int>> &matrix, vector<int> &nums)
{
	int x = 0, y = 0;
	vector<vector<int>> visited(5, vector<int>(5,0));
	for(int i = 0; i < 5; i++)
	{
	    for(int j = 0; j < 5; j++)
	    {
			if(matrix[i][j] == nums[0])
			{
				x = i; y = j;
				std::cout << "find:" << nums[0] << "in" << x << "," << y << ":" << matrix[i][y] << endl;
			}
	    }
	}
	int steps = 0;
	MoveInNeibor(matrix, nums, visited, x, y, steps);
	if(steps == 6)
		return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	vector<vector<int>> matrix;
	matrix.push_back(vector<int> {1,2,3,4,5});
	matrix.push_back(vector<int> {11,12,13,14,15});
	matrix.push_back(vector<int> {21,22,23,24,25});
	matrix.push_back(vector<int> {31,32,33,34,35});
	matrix.push_back(vector<int> {41,42,43,44,45});

	std::string line;
	while(getline(cin, line))
	{
		std::stringstream ss(line);
		vector<int> nums;
		int n;
		while(ss >> n)
			nums.push_back(n);
		std::cout << IsNeighbor(matrix, nums) << std::endl;
	}

    return 0;
}
