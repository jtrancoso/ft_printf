# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/15 11:40:04 by jtrancos          #+#    #+#              #
#    Updated: 2020/10/04 14:16:47 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_print_c.c ft_print_s.c ft_print_id.c ft_print_x_lower.c ft_print_x_upper.c ft_print_u.c ft_print_p.c ft_flags.c ft_filling.c ft_printf_utils.c
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
.c.o:
				${CC} ${FLAGS} -c $< -o ${<:.c=.o}
${NAME}:		${OBJS}
							make -C ./libft/
							cp libft/libft.a ${NAME}
							ar rc ${NAME} ${OBJS}
							ranlib ${NAME}
all:			${NAME}
clean:						
							${RM} ${OBJS}
							make clean -C libft/
fclean:			clean
							${RM} ${NAME}
							make fclean -C libft/
re:				fclean all
.PHONY:			all clean fclean re