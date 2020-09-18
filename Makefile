# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/15 11:40:04 by jtrancos          #+#    #+#              #
#    Updated: 2020/09/18 13:25:15 by jtrancos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_print_c.c ft_print_s.c ft_flags.c ft_filling.c
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