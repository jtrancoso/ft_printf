/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:04:23 by jtrancos          #+#    #+#             */
/*   Updated: 2020/09/15 13:12:00 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	space_or_zero(char *str, int i, t_flags *flags)
{
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
		{
			flags->minus = 1;
			flags->zero = -1;
		}
		if (str[i] == '0' && flags->minus == -1)
			flags->zero = 1;
		i++;
	}
}

void	start_flags(t_flags *flags)
{
	flags->precision = -1;
	flags->width = -1;
	flags->zero = -1;
	flags->minus = -1;
}
