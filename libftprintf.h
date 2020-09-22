/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 13:19:20 by jtrancos          #+#    #+#             */
/*   Updated: 2020/09/22 12:55:02 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct	s_flags
{
	int		minus;
	int		zero;
	int		precision;
	int		width;
	int		count;
}				t_flags;

int		ft_printf(const char *s, ...);
void	ft_print_c(int c, t_flags *flags);
void	ft_print_s(va_list args, t_flags *flags);
void	find_string(char **s, int *len, va_list args, t_flags *flags);
void	space_or_zero(const char *s, int *i, t_flags *flags);
void	check_width(const char *s, int *i, va_list args, t_flags *flags);
void	check_star(const char *s, int *i, va_list args, t_flags *flags);
void	check_point(const char *s, int *i, va_list args, t_flags *flags);
void	check_flags(const char *s, int *i, va_list args, t_flags *flags);
int		ft_filling(int n, int class);
void	start_flags(t_flags *flags);

#endif
