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
	if (flags->width != -1)
	{
		if (flags->minus == 1)
		{
			flags->count += write(1, &c, 1);
			flags->count += ft_filling(flags->width - 1, flags->zero);
		}
		else
		{
			flags->count += ft_filling(flags->width - 1, flags->zero);
			flags->count += write(1, &c, 1);
		}
	}
	else
		flags->count += write(1, &c, 1);
}
