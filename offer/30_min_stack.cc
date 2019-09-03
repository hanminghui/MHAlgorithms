#include <iostream>
#include <stack>

class MinStack
{
public:
	void Push(int num);
	void Pop();
	int Min();
private:
	std::stack<int> data_;
	std::stack<int> min_;
};

void MinStack::Push(int num)
{
	data_.push(num);
	if(min_.empty() || num < min_.top())
		min_.push(num);
	else
		min_.push(min_.top());
}

void MinStack::Pop()
{
	data_.pop();
	min_.pop();
}

int MinStack::Min()
{
	return min_.top();
}

int main(int argc, char *argv[])
{
	MinStack a_minstack;
	a_minstack.Push(3);
	std::cout << a_minstack.Min() << std::endl;
	a_minstack.Push(4);
	std::cout << a_minstack.Min() << std::endl;
	a_minstack.Push(2);
	std::cout << a_minstack.Min() << std::endl;
	a_minstack.Push(1);
	std::cout << a_minstack.Min() << std::endl;
	a_minstack.Pop();
	std::cout << a_minstack.Min() << std::endl;
	a_minstack.Pop();
	std::cout << a_minstack.Min() << std::endl;
	a_minstack.Push(0);
	std::cout << a_minstack.Min() << std::endl;
    return 0;
}
