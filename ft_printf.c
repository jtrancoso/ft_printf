/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 12:02:12 by jtrancos          #+#    #+#             */
/*   Updated: 2020/09/09 13:13:48 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_format(const char *s, int i, va_list args)
{
	if (s[i] == 'd' || s[i] == 'i')
	{
		int h = va_arg(args, int);
		write(1, &h, 1);
	}
	else if (s[i] == 'c')
	{
		char c = (char)va_arg(args, int);
		write(1, &c, 1);
	}
	else if (s[i] == 's')
	{
		char *hola = va_arg(args, char *);
		write(1, hola, strlen(hola));
	}
	return (i);
}

int		ft_printf(const char *s, ...)
{
	va_list		args;
	int i;

	va_start(args, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			check_format(s, i, args);
		}
		else 
		{
			write(1, &s[i], 1);
		}
		i++;
	}
	va_end(args);
	return (0);
}

int		main(void)
{
	int		i;
	char	c;
	char	s[100] = "hola que tal";
	
	i = '3';
	c = 'z';
	ft_printf("Imprime int = %i\n", i);
	ft_printf("Imprime char = %c\n", c);
	ft_printf("Imprime string = %s\n", s);
	//ft_printf("Imprime unsigned dec = %u\n", i);
	
}
