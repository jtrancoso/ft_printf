/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 12:02:12 by jtrancos          #+#    #+#             */
/*   Updated: 2020/09/23 12:32:22 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		check_format(const char *s, int *i, va_list args, t_flags *flags)
{
	if (s[*i] == 'c')
		ft_print_c((char)va_arg(args, int), flags);
	else if (s[*i] == 's')
		ft_print_s(args, flags);
	else if (s[*i] == '%')
		ft_print_c('%', flags);
	else if (s[*i] == 'd' || s[*i] == 'i')
		ft_print_id(args, flags);

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
			check_flags(s, &i, args, &flags);
			check_format(s, &i, args, &flags);
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
