#include <iostream>
#include <stack>

struct binarytree
{
	binarytree(){};
	binarytree(int d)
	{
		data = d;
		left = nullptr;
		right = nullptr;
	}
	int data;
	binarytree * left;
	binarytree * right;
};

void in_traverse0(binarytree *);
void in_traverse1(binarytree *);
void pre_traverse0(binarytree *);
void pre_traverse1(binarytree *);
void post_traverse0(binarytree *);
void post_traverse1(binarytree *);

int main(int argc, char *argv[])
{
	binarytree * root = new binarytree(0);
	binarytree * a = new binarytree(1);
	binarytree * b = new binarytree(2);
	binarytree * c = new binarytree(3);
	binarytree * d = new binarytree(4);
	binarytree * e = new binarytree(5);
	binarytree * f = new binarytree(6);
	root->left = a; root->right = b;
	a->left = c; a->right = d;
	b->left = e; b->right =f;

	std::cout << "pre order:" << std::endl;
	pre_traverse0(root);
	std::cout << std::endl;
	pre_traverse1(root);
	std::cout << std::endl;
	std::cout << "in order:" << std::endl;
	in_traverse0(root);
	std::cout << std::endl;
	in_traverse1(root);
	std::cout << std::endl;
	std::cout << "post order:" << std::endl;
	post_traverse0(root);
	std::cout << std::endl;
	post_traverse1(root);
	std::cout << std::endl;

    return 0;
}

/* preorder traverse
 * recursive
 */
void pre_traverse0(binarytree *root)
{
	if(!root)
		return;
	std::cout << root->data << " ";
	if(root->left)
	    pre_traverse0(root->left);
	if(root->right)
		pre_traverse0(root->right);
}

/* preorder_traverse
 * iterative
 */
void pre_traverse1(binarytree *root)
{
	std::stack<binarytree*> s;
	if(root)
		s.push(root);
	while(!s.empty())
	{
		binarytree *temp = s.top();
		std::cout << temp->data << " ";
		s.pop();
		if(temp->right)
			s.push(temp->right);
		if(temp->left)
			s.push(temp->left);
	}
}

/* inorder traverse
 * recursive
 */
void in_traverse0(binarytree *root)
{
	if(!root)
		return;
    if(root->left)
		in_traverse0(root->left);
	std::cout << root->data << " ";
	if(root->right)
		in_traverse0(root->right);
}

/* inorder traverse
 * iterative
 */
void in_traverse1(binarytree *root)
{
	if(!root)
		return;
	std::stack<binarytree*> s;
	binarytree *cur = root;
	while(cur || !s.empty())
	{
		while(cur)
		{
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		s.pop();
		std::cout << cur->data << " ";
		cur = cur->right;
	}
}

/* post traverse
 * recursive
 */
void post_traverse0(binarytree* root)
{
	if(!root)
		return;
	if(root->left)
		post_traverse0(root->left);
	if(root->right)
		post_traverse0(root->right);
	std::cout << root->data << " ";
}

/* post traverse
 * iterative
 */
void post_traverse1(binarytree * root)
{
	if(!root)
		return;
	std::stack<binarytree *> s;
	binarytree * cur;
	binarytree * pre = nullptr;
	s.push(root);
	while(!s.empty())
	{
		cur = s.top();
		if((cur->left == nullptr && cur->right == nullptr) || 
			(pre != nullptr && (pre == cur->left || pre == cur->right)))
		{
			std::cout << cur->data << " ";
			s.pop();
			pre = cur;
		}
		else
		{
			if(cur->right != nullptr)
				s.push(cur->right);
			if(cur->left != nullptr)
				s.push(cur->left);
		}
	}
}
