#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

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

void SerializeCore(binarytree *root, std::string &s)
{
	if(!root)
	{
		s += '#';
		return;
	}
	s += std::to_string(root->data);
	s += '!';
	SerializeCore(root->left, s);
	SerializeCore(root->right, s);
}

char* Serialize(binarytree *root)
{
	if(!root)
		return nullptr;
	std::string s;
	SerializeCore(root, s);
	char *result = new char[s.size()+1];
	s.copy(result, s.size());
	result[s.size()] = '\0';
	return result;
}

binarytree* DeserializeCore(char*&str)
{
	if(*str == '#')
	{
		str++;
		return nullptr;
	}
	int num = 0;
	while(*str != '\0' && *str != '!')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	binarytree * root = new binarytree(num);
	if(*str == '\0')
		return root;
	else
		str++;
	root->left = DeserializeCore(str);
	root->right = DeserializeCore(str);
	return root;
}

binarytree* Deserialize(char *str) {
	if(!str)
		return nullptr;
	binarytree * root = DeserializeCore(str);
	return root;
}

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
	a->left = c;
	b->left = e; b->right =f;

	std::cout << "pre order:" << std::endl;
	pre_traverse0(root);
	std::cout << std::endl;

	char * s = Serialize(root);
	printf("%s", s);
	std::cout << std::endl;

	binarytree *des = Deserialize(s);

	std::cout << "pre order:" << std::endl;
	pre_traverse0(des);
	std::cout << std::endl;

	return 0;
}
