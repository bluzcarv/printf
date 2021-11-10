# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bluzcarv <bluzcarv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 15:16:32 by bluzcarv          #+#    #+#              #
#    Updated: 2021/10/18 16:31:33 by bluzcarv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCR	=	ft_printf.c \
			ft_printf_utils.c \
			ft_print_u.c \
			ft_print_p.c \
			ft_print_hexa.c

OBJS	= ${SRCR:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
