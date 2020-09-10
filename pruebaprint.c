#include <stdio.h>

int main (void)
{
	int i = 45;
	int u = 2;
	printf("%03d\n", i);
	printf("%03d\n", u);
	printf("%-3d\n", i);
	printf("%-3d\n", u);
}