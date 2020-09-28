/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:33:22 by jtrancos          #+#    #+#             */
/*   Updated: 2020/09/28 13:33:17 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	start_flags(t_flags *flags)
{
	flags->precision = -1;
	flags->width = -1;
	flags->zero = -1;
	flags->minus = -1;
}

void	put_hex(int n, char lettercase, t_flags *flags)
{
	int hex;

	if (n == 0 && flags->precision == 0)
		return ;
	if (n >= 16)
		put_hex(n / 16, lettercase, flags);
	hex = n % 16;
	if (hex > 9)
	{
		if (lettercase == 'l')
			hex += 87;
		if (lettercase == 'u')
			hex += 55;
	}
	else
		hex += '0';
	flags->count += write(1, &hex, 1);
}
