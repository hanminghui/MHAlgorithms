#include <iostream>
#include <cmath>

const char ch = '@';

void print_rectangle(int w, int h);
void print_right_triangle(int b);

int main(int argc, char *argv[])
{
	std::cout << "rectangle:" << std::endl;
	print_rectangle(10,5);
	std::cout << "right triangle:" << std::endl;
	print_right_triangle(9);
    return 0;
}

/* w, width
 * h, height
 */
void print_rectangle(int w, int h)
{
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			std::cout << ch;
		}
			std::cout << std::endl;
	}
}

/* h, height
 */
void print_right_triangle(int h)
{
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < i+1; j++)
		{
		    std::cout << ch;
		}
		std::cout << std::endl;
	}
}
