#include "libftprintf.h"

int		main(void)
{
	char	c = 'z';
	char	s[100] = "hola que tal";
	
	//ft_printf("Imprime int = %i\n", i);
	ft_printf("%c%c%c%c%c%c%c%c%c%c\n", c, c, c, c, c, c, c, c, c, c);
	ft_printf("hola\n");
	ft_printf("%s\n", s);
	//ft_printf("Imprime string = %s\n", s);
	//ft_printf("Imprime unsigned dec = %u\n", i);
}