# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/23 10:25:32 by dmalori           #+#    #+#              #
#    Updated: 2021/01/23 16:23:47 by dmalori          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -c

LIB			= ar -rc

RAN			= ranlib

SRCS		= 	ft_printf.c \
				ft_core_digit.c \
				ft_core_minus.c \
				ft_core_point.c \
				ft_core_print.c \
				ft_core_star.c \
				ft_core_zero.c \
				ft_initflags.c \
				ft_isdigit.c \
				ft_isterminator.c \
				ft_print_char.c \
				ft_print_decimal.c \
				ft_print_decimal_neg.c \
				ft_print_decimal_unsigned.c \
				ft_print_exa.c \
				ft_print_zero.c \
				ft_print_pointer.c \
				ft_print_pointer_NULL.c \
				ft_print_string.c \
				ft_print_string_NULL.c \
				ft_putlchar.c \
				ft_putlstr.c \
				ft_strlen.c \
				ft_toupper.c \
				ft_atoi_abs.c \
				ft_itoa_base.c \
				ft_itoa_base_unsigned.c \
				ft_min.c \
				ft_max.c \
				ft_toupper.c \
				ft_toupperstr.c

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

%.o:		%.c
			${CC} ${CFLAGS} $<

$(NAME):	${OBJS}
			${LIB} ${NAME} ${OBJS}
			${RAN} ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re