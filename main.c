#include "libftprintf.h"

int		main(void)
{
	int		i;
	char	c;
	char	s[100] = "hola que tal";
	
	i = '3';
	c = 'z';
	//ft_printf("Imprime int = %i\n", i);
	ft_printf("Mi printf = %c\n", c);
	ft_printf("Mi printf = %c %c\n", c, c);
	printf("Real printf = %c\n", c);
	printf("Mi printf = %c %c\n", c, c);
	//ft_printf("Imprime string = %s\n", s);
	//ft_printf("Imprime unsigned dec = %u\n", i);
}