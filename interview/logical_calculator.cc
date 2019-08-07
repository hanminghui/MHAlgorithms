#include <iostream>
#include <stack>

using namespace std;
int cal(int a, int b, int op);

int main(int argc, char *argv[])
{
	stack<int> op;
	stack<int> num;

	char* p = "1&1";

	while(*p != '\0')
	{
		if(*p == '1' || *p == '0')
			num.push(*p);
		else
			op.push(*p);
		p++;
	}

	int temp = op.top();
	op.pop();
	int a, b;
	a = num.top(); num.pop();
	b = num.top(); num.pop();

	int result = cal(a, b, temp);

	std::cout << a << b << temp << std::endl;

	std::cout << result << std::endl;

    return 0;
}

int cal(int a, int b, int op)
{
	if(op == '&')
	{
		if(a == '1', b == '1')return 1;
	}
}
