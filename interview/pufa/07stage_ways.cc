#include <iostream>
#include <vector>

using namespace std;

int ways(int stages);

int main(int argc, char *argv[])
{
	std::vector<int> stages;
	int stage;
	cin >> stage;
	stages.push_back(stage);
	while(stage != 0)
	{
		cin >> stage;
		stages.push_back(stage);
	}

	for(auto s : stages)
		if(s != 0)
			std::cout << ways(s) << std::endl;
    return 0;
}

int ways(int stages)
{
	if(stages == 1)
	{
	    return 1;
	}
	if(stages == 2)
	{
	    return 2;
	}
	return ways(stages -1) + ways(stages - 2);
}
