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

void post_traverse0(binarytree *);
void post_traverse1(binarytree *);

int main(int argc, char *argv[])
{
	binarytree * root = new binarytree(0);
	binarytree * a = new binarytree(1);
	binarytree * b = new binarytree(2);
	binarytree * c = new binarytree(3);
	binarytree * d = new binarytree(4);
	root->left = a; root->right = b;
	a->left = c; a->right = d;

	post_traverse0(root);
	std::cout << std::endl;
	post_traverse1(root);

    return 0;
}

/* post traverse
 * recursive
 */
void post_traverse0(binarytree* root)
{
	if(root->left)
		post_traverse0(root->left);
	if(root->right)
		post_traverse0(root->right);
	std::cout << root->data << " ";
}

/* post traverse
 * non recursive
 */
void post_traverse1(binarytree * root)
{
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
