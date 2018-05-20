// Find the kth node to the tail in a list
#include <iostream>
#include "List.h"

ListNode* FindKthToTail0(ListNode * pListHead, unsigned int k);

int main ()
{
	List list;
	for(int i = 1; i <= 100; i++)
	{
		list.add(i);
	}
	list.print();
	int l = list.getlength();
	std::cout << l << std::endl;

	int k, num;
	k = 8;
	ListNode* n = FindKthToTail0(list.firstNode(), k);
	std::cout << "The " << k << " node to the tail is " << n->data << std::endl;

	return 0;
}

ListNode* FindKthToTail0(ListNode * pListHead, unsigned int k)
{
	ListNode* pAhead = pListHead;
	ListNode* pBehind = nullptr;
	for(int i = 0; i < k-1; ++i)
	{
		pAhead = pAhead->next;
	}
	pBehind = pListHead;
	while(pAhead->next)
	{
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	return pBehind;
}
