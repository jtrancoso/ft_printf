/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 13:26:41 by jtrancos          #+#    #+#             */
/*   Updated: 2020/09/23 13:37:26 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		find_len(int n, t_flags *flags)
{
	int aux;
	int len;

	if (n == 0 && flags->precision == 0)
		len = 0;
	else
	{
		len = 1;
	}
	aux = n;
	while (aux / 10 != 0)
	{
		aux = aux / 10;
		len++;
	}
	return (len);
}

int		find_true_len(int n, int len, t_flags *flags)
{
	int true_len;

	true_len = len;
	if (flags->precision > len)
		true_len = flags->precision;
	if (n < 0)
		true_len++;
	return (true_len);
}

void	ft_print_id(va_list args, t_flags *flags)
{
	int n;
	int len;
	int true_len;

	n = va_arg(args, int);
	len = find_len(len, flags);
	true_len = find_true_len(true_len, len, flags);
	printf("len = %d true_len = %d\n", len, true_len);
}
