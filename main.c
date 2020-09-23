#include "libftprintf.h"

int		main(void)
{
	char	c = 'z';
	char	s[100] = "hola que tal";
	char 	str[100] = "hello";
	int i = 7;
	
	//ft_printf("Imprime int = %i\n", i);
	ft_printf("%c%c%c%c%c%c%c%c%c%c\n", c, c, c, c, c, c, c, c, c, c);
	ft_printf("hola\n");
	ft_printf("1 =%s, 2=%s\n", s, s);
	ft_printf("hello %s.\n", NULL);
	ft_printf("%%\n");
	ft_printf("%5\n");
	ft_printf("%d\n", i);
	ft_printf("%-5d\n", i);
	//ft_printf("Imprime string = %s\n", s);
	//ft_printf("Imprime unsigned dec = %u\n", i);
}