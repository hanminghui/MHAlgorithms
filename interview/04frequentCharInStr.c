#include <stdio.h>

int main ()
{
	printf("Enter a string:\n");
	char str[1024];
	gets(str);
	printf("You entered: %s.\n", str);

	int count[256] = {0};

	int i = 0;
	while(str[i])
	{
		count[(int)str[i]] += 1;
		i++;
	}

	char frequentCh = 0;
	int max = 0;

	for(int i = 0; i < 256; i++)
	{
		printf("%d", count[i]);
	}
	printf("\n");

	for(int i = 0; i < 256; i++)
	{
		if(count[i] > max)
		{
			max = count[i];
			frequentCh = (char)i;
			printf("%d,%d,%c; ", i, max, frequentCh);
		}
	}

	printf("\n");
	printf("The most frequent character is %c, and it apears %d times.\n", 
			frequentCh, max);

	return 0;
}
