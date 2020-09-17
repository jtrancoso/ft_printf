/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:04:23 by jtrancos          #+#    #+#             */
/*   Updated: 2020/09/17 13:40:57 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	space_or_zero(const char *s, int i, t_flags *flags)
{
	while (s[i] == '-' || s[i] == '0')
	{
		if (s[i] == '-')
		{
			flags->minus = 1;
			flags->zero = -1;
		}
		if (s[i] == '0' && flags->minus == -1)
			flags->zero = 1;
		i++;
	}
}

void	check_width(const char *s, int i, va_list args, t_flags *flags)
{
	if (s[i] > '0' && s[i] <= '9')
	{
		flags->width = ft_atoi(&s[i]);
		while (s[i] >= '0' && s[i] <= '9')
			i++;
	}
}

void	check_flags(const char *s, int i, va_list args, t_flags *flags)
{
	space_or_zero(s, i, flags);
	check_width(s, i, args, flags);
}

void	start_flags(t_flags *flags)
{
	flags->precision = -1;
	flags->width = -1;
	flags->zero = -1;
	flags->minus = -1;
}
