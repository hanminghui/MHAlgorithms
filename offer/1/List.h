#include <iostream>

typedef struct node
{
	int data;
	node * next;
}ListNode;

class List
{
	ListNode * head;
	int length;
public:
	List()
	{
		head = nullptr;
		length = 0;
	}

	int getlength()
	{
		return length;
	}
	bool isEmpty() {return head == nullptr;}

	ListNode* firstNode() {return head;}

	void add(int num)
	{
		if(this->isEmpty())
		{
			head = new ListNode;
			head->data = num;
			head->next = nullptr;
			length++;
		}
		else
		{
			ListNode* last = head;
			while(last->next)
			{
				last = last->next;
			}
			last->next = new ListNode;
			last->next->data = num;
			last->next->next = nullptr;
			++length;
		}
	}
	void print()
	{
		ListNode* last = head;
		while(last)
		{
			std::cout << last->data << " ";
			last = last->next;
		}
		std::cout << std::endl;
	}

};
