/* input: a int
 * output: firstline, first occurence
 *         secondline, number of occurence
 */
#include <iostream>
#include <bitset>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

void find101(int input);

int main(int argc, char *argv[])
{
	int input;
    cin >> input;
	bitset<sizeof(int)*8> bit(input);
	std::cout << bit << std::endl;

	find101(input);

    return 0;
}

void find101(int input)
{
	int count101 = 0;   /* 101的个数 */
    int	bitcount = 0;   /* 总位数 */
	int find101 = 0;    /* 是否找到 */
	int	first101 = 3;   /* 第一个101位置，倒序 */
	unsigned n = (unsigned int)input;       /* int为负时右移补1，故转为unsigned */
	while(n)                                /* n 不为0 */
	{
		if((n & 7) == 5)                    /* 7:111, 5:101 */
		{
			count101++;
			find101 = 1;
			first101 += bitcount;
		}
		n = n >> 1;
		bitcount++;
	}
	if(find101)                             /* 找到了 */
		first101 = bitcount - first101;
	else                                    /* 未找到 */
		first101 = 0;
	std::cout << "count:" << count101 << std::endl;
	std::cout << "first:" << first101 << std::endl;
}
