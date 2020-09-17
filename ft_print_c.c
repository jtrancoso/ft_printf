/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:58:09 by jtrancos          #+#    #+#             */
/*   Updated: 2020/09/14 11:42:35 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_c(int c, t_flags *flags)
{
	if (flags->width > 0)
	{
		if (flags->minus == 1)
		{
			flags->count += write(1, &c, 1);
			ft_filling(flags->width, flags->zero);
		}
		else
		{
			ft_filling(flags->width, flags->zero);
			flags->count += write(1, &c, 1);
		}
	}
/*	if (flags->width > 0 && flags->minus == -1)
		flags->count += ft_filling(flags->width - sizeof(char), flags->zero);
	flags->count += write(1, &c, 1);
	if (flags->width > 0 && flags->minus == 1)
		flags->count += ft_filling(flags->width - sizeof(char), flags->zero);
		*/
}