#include <stack>
#include <string>
#include <iostream>

using namespace std;

struct opval
{
    char op;
	int val;
	opval(char a, int b)
	{
		op = a; val = b;
	}
};
stack<opval> stack_opval;

int cal(const char* index);
int run(int rv);
int operation(char op, int lv, int rv);
int rev(int v);

int main(int argc, char *argv[])
{
	std::cout << "0    : " << cal("0") << std::endl;
	std::cout << "1    : " << cal("1") << std::endl;
	std::cout << "!0   : " << cal("!0") << std::endl;
	std::cout << "!1   : " << cal("!1") << std::endl;
	std::cout << "0|1&0: " << cal("0|1&0") << std::endl;
	std::cout << "1&0|1: " << cal("1&0|1") << std::endl;
	std::cout << "0&1&1: " << cal("0&1&1") << std::endl;
	std::cout << "1&0|1: " << cal("1&0|1") << std::endl;
	std::cout << "1&1|0: " << cal("1&1|0") << std::endl;

    return 0;
}

int cal(const char* index)
{
	int v;
	while(*index)
	{
		if(*index == '1' || *index == '0')
		{
			v = *index - '0';
		}
		if(*index == '&')
		{
			stack_opval.push(opval(*index, v));
		}
		if(*index == '|')
		{
			if(!stack_opval.empty() && stack_opval.top().op == '&')
			{
				v = run(v);
			}
			stack_opval.push(opval(*index, v));
		}
		if(*index == '!')
		{
			if(stack_opval.empty())
			{
				index++;
				v = rev(cal(index));
			}
			else
			{
				index++;
				v = run(rev(cal(index)));
			}
		}
		index++;
	}
	return run(v);
}

int run(int rv)
{
	while(!stack_opval.empty())
	{
		auto s = stack_opval.top();
		char op = s.op;
		int lv = s.val;
		rv = operation(op, lv, rv);
		stack_opval.pop();
	}
	return rv;
}

int operation(char op, int lv, int rv)
{
	if(op == '&')
	{
		if(lv == 1 && rv == 1) return 1;
		else return 0;
	}
	if(op == '|')
	{
		if(lv == 0 && rv == 0) return 0;
		else return 1;
	}
}

int rev(int v)
{
	if(v == 0) return 1;
	else return 0;
}
