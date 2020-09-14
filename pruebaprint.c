#include <stdio.h>

int main (void)
{
	char i = 's';
	char u = 'z';
	//printf("%03c\n", i);
	printf("Real printf = %-3c\n", u);
	printf("Real printf = %03c\n", u);
	//printf("%-3c\n", u);
}