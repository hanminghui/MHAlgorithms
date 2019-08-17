#include <iostream>
#include <bitset>

int main(int argc, char *argv[])
{
    int num = 5;
	std::cout << "int:   " << num << std::endl;
	std::bitset<sizeof(int) * 8> bit(num);
	std::cout << "bit:   " << bit << std::endl;

	std::cout << "size:  " << bit.size() << std::endl;
	std::cout << "count: " << bit.count() << std::endl;

	num = -1;
	bit = num;
	std::cout << "int:   " << num << std::endl;
	std::cout << "bit:   " << bit << std::endl;

	/* if you right shift on int, result may be different */
	bit >>= 2;
	std::cout << "after 2 right shift, on bitset: " << std::endl;
	std::cout << "bit:   " << bit << std::endl;
	num >>= 2;
	bit = num;
	std::cout << "after 2 right shift, on int: " << std::endl;
	std::cout << "bit:   " << bit << std::endl;
	/* no guarantees for how the sign bit is handled
	 * use unsigned
	 */

	bit = ~bit;
	std::cout << "bit:   " << bit << std::endl;
	bit.flip();
	std::cout << "bit:   " << bit << std::endl;

    return 0;
}
