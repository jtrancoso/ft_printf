/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 12:02:12 by jtrancos          #+#    #+#             */
/*   Updated: 2020/09/14 13:36:21 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_format(const char *s, int i, va_list args, t_flags *flags)
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
	return (i);
}

int		ft_printf(const char *s, ...)
{
	va_list		args;
	int i;

	va_start(args, s);
	i = 0;
	t_flags		flags;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			start_flags(&flags);
			check_format(s, i, args, &flags);
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