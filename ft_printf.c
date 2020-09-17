/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 12:02:12 by jtrancos          #+#    #+#             */
/*   Updated: 2020/09/17 13:48:43 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		check_format(const char *s, int i, va_list args, t_flags *flags)
{
	if (s[i] == 'd' || s[i] == 'i')
	{
		int h = va_arg(args, int);
		write(1, &h, 1);
	}
	else if (s[i] == 'c')
	{
		ft_print_c((char)va_arg(args, int), flags);
	}
	else if (s[i] == 's')
	{
		char *hola = va_arg(args, char *);
		write(1, hola, strlen(hola));
	}
	if (s[i])
		i++;
}

int		ft_printf(const char *s, ...)
{
	int			i;
	va_list		args;
	t_flags		flags;

	va_start(args, s);
	i = 0;
	flags.count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			start_flags(&flags);
			printf("width = %d\n", flags.width);
			printf("minus = %d", flags.minus);
			printf("zero = %d", flags.zero);
			check_flags(s, i, args, &flags);
			printf("width = %d\n", flags.width);
			printf("minus = %d", flags.minus);
			printf("zero = %d", flags.zero);
			check_format(s, i, args, &flags);
		}
		else
		{
			flags.count += write(1, &s[i], 1);
		}
		i++;
	}
	va_end(args);
	return (flags.count);
}
