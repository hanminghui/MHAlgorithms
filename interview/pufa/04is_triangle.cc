#include <iostream>

void isTriangle();

int main(int argc, char *argv[])
{
    std::cout << "input 3 numbers:" << std::endl;

	isTriangle();

    return 0;
}

void isTriangle()
{
	int a, b, c;
	std::cin >> a >> b >> c;
	if( (a+b)>c && (a+c)>b && (b+c)>a )
		std::cout << "is a triangle." << std::endl;
	else
		std::cout << "not a triangle." << std::endl;
}
