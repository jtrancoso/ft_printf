/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 13:23:10 by jtrancos          #+#    #+#             */
/*   Updated: 2020/09/21 12:41:01 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_s(va_list args, t_flags *flags)
{
	char *s;
	int len;

	s = ft_strdup(va_arg(args, char *));
	len = ft_strlen(s);
	if (flags->width != -1)
	{
		if (flags->minus == 1)
		{
			flags->count += write(1, s, len);
			flags->count += ft_filling(flags->width - len, flags->zero);
		}
		else
		{
			flags->count += ft_filling(flags->width - len, flags->zero);
			flags->count += write(1, s, len);
		}
	}
	else
		flags->count += write(1, s, len);
}
