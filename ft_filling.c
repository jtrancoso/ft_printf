/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:46:13 by jtrancos          #+#    #+#             */
/*   Updated: 2020/09/14 13:43:18 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_filling(int n, int class)
{
	int i;

	i = 0;
	if (class == -1)
	{
		while (i < n)
		{
			write(1, " ", 1);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			write(1, "0", 1);
			i++;
		}
	}
	return (i);
}