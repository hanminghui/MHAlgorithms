/* my atoi function
 */
#include <stdio.h>
#include <stdlib.h>

int myatoi(const char *);

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: atoi [number]\n");
		exit(1);
    }
	printf("System atoi: %d\n", atoi(argv[1])); /* system implementation */
	printf("The number you input: %d\n", myatoi(argv[1])); /* my implementation */
    return 0;
}

int myatoi(const char * str)
{
    int rv = 0;
	bool negative = 0;
	if(*str == '-')
	{
		negative = 1;
		str++;
	}
	else if(*str == '+')
	{
		str++;
	}
	else if(*str < '0' || *str > '9')
	{
		return 0;
	}
	while(str)
	{
		if(*str < '0' || *str > '9')
			break;
		rv *= 10;
	    rv += *str - '0';
		++str;
	}

	if(negative) return -rv;
	return rv;
}
