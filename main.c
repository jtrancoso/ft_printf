#include "libftprintf.h"

int		main(void)
{
	char	c = 'z';
	char	s[100] = "hola que tal";
	char 	str[100] = "hello";
	int i = 7;
	int a = -267;
	
	//ft_printf("Imprime int = %i\n", i);
	ft_printf("%c%c%c%c%c%c%c%c%c%c\n", c, c, c, c, c, c, c, c, c, c);
	ft_printf("hola\n");
	ft_printf("1 =%s, 2=%s\n", s, s);
	ft_printf("hello %s.\n", NULL);
	ft_printf("%%\n");
	ft_printf("%5\n");
	printf("Real: %d, %.2d\n", i, i);
	ft_printf("Mio: %d, %.2d\n", i, i);
	printf("Real: %d, %.5d\n", a, a);
	ft_printf("Mio: %d, %.5d\n", a, a);
	//ft_printf("Imprime string = %s\n", s);
	//ft_printf("Imprime unsigned dec = %u\n", i);
}