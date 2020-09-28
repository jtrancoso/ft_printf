/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:16:40 by jtrancos          #+#    #+#             */
/*   Updated: 2020/09/28 13:51:47 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		find_hex_len(unsigned int n, t_flags *flags)
{
	int hex_len;

	if (flags->precision == 0 && n == 0)
		hex_len = 0;
	else
		hex_len = 1;
	while (n / 16 != 0)
	{
		n /= 16;
		hex_len++;
	}
	return (hex_len);
}

void	ft_print_hexnum_lower(int *n, int *hex_len, t_flags *flags)
{
	int i;

	i = 0;
	while (i < (flags->precision - *hex_len))
	{
		flags->count += write(1, "0", 1);
		i++;
	}
	ft_put_hex(*n, 'l', flags);
}

void	ft_print_x_lower(va_list args, t_flags *flags)
{
	int n;
	int hex_len;
	int true_len;

	n = va_arg(args, int);
	hex_len = find_hex_len(n, flags);
	if (flags->precision > hex_len)
		true_len = flags->precision;
	else
		true_len = hex_len;
	if (flags->width > true_len)
	{
		if (flags->minus == 1)
		{
			flags->count += ft_print_hexnum_lower(&n, &true_len, flags);
			flags->count += ft_filling(flags, true_len);
		}
		else
		{
			flags->count += ft_filling(flags, true_len);
			flags->count += ft_print_hexnum_lower(&n, &true_len, flags);
		}
	}
	else
		flags->count += ft_print_hexnum_lower(n, true_len, flags);
}
