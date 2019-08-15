#include <map>
#include <string>
#include <iostream>

template <typename T, typename U>
void printmap(std::map<T, U>& amap);
void numsinfunction(int nums[]);

int main(int argc, char *argv[])
{
	std::map<std::string, int> wordcount, * p = &wordcount, &refwc = wordcount;
	wordcount["a"] = 0;
	wordcount["b"] = 1;
	wordcount["c"] = 2;

	std::cout << "sizeof(pointer):" << sizeof(p) << std::endl;
	std::cout << "sizeof(deref a pointer):" << sizeof(*p) << std::endl;
	std::cout << "sizeof(reference):" << sizeof(refwc) << std::endl;

	printmap(wordcount);

	int nums[10];
	int * pnum = nums;
	std::cout << "sizeof(array):" << sizeof(nums) << std::endl;
	numsinfunction(nums);
	std::cout << "sizeof(pointer to array):" << sizeof(pnum) << std::endl;
	char * chars = "fuck";
	std::cout << "sizeof(pointer to char):" << sizeof(chars) << std::endl;

	char name[11] = "Hanminghui";
	chars = name;
	std::cout << chars << std::endl;

    return 0;
}

template <typename T, typename U>
void printmap(std::map<T, U>& amap)
{
	for(const auto& element : amap)
	{
		std::cout << "{key:" << element.first << ", "
			      << "value:" << element.second << "}" << std::endl;
	}
}

void numsinfunction(int nums[])
{
	std::cout << "sizeof(array in function):" << sizeof(nums) << std::endl;
}
