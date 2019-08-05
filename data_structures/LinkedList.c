#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
	struct node * next;
}Node;

Node* create(int data)
{
    Node * list = (Node*)malloc(sizeof(Node));
	list->data = data;
	list->next = NULL;
	return list;
}

int append(Node * head, int data)
{
	while(head->next)
	{
	    head = head->next;
	}
    Node * newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = NULL;

	head->next = newnode;
	return 0;
}

Node* reverse(Node * list)
{
	if(!list)
	{
		return list;
	}
	Node * cur, * next, *temp;
	cur = list;
	next = cur->next;
	cur->next = NULL;

	while(next)
	{
		temp = next->next;
		next->next = cur;
		cur = next;
		next = temp;
	}

	Node * newlist = cur;
	return newlist;
}

Node* reverse_recursive(Node * list)
{
	if(list == NULL || list->next == NULL)
	{
	    return list;
	}
	Node * temp = list->next;
	Node * newlist = reverse_recursive(temp);
	temp->next = list;
	list->next = NULL;
	return newlist;
}

int print(Node * head)
{
	if(!head)
	{
	    printf("Empty List");
	}
	while(head)
	{
		printf("%d;", head->data);
		head = head->next;
	}
	printf("\n");
	return 0;
}

int main(int argc, char *argv[])
{
	Node * list = create(0);
	print(list);
	for(int i = 0; i < 10; i++)
	{
	    append(list,  (i+1));
	}
	print(list);
	Node * newlist = reverse(list);
	print(newlist);
	Node * newlist_r = reverse_recursive(newlist);
	print(newlist_r);
    return 0;
}
