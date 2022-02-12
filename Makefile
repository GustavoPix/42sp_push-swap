# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 19:56:15 by glima-de          #+#    #+#              #
#    Updated: 2021/12/06 19:56:15 by glima-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_MANDATORY = ./main.c \

OBJS 		= ${SRCS:.c=.o}
OBJS_M		= ${SRCS_MANDATORY:.c=.o}

LIBFT 		= libft

SLG_UTL		= ./src/clear.c \
			  ./src/debug.c \
			  ./src/order.c \
			  ./src/moves/moves.c \
			  ./src/moves/moves_a.c \
			  ./src/moves/moves_b.c \
			  ./src/moves/moves_s.c \
			  ./src/sort/radix.c \
			  ./src/sort/radix2.c \
			  ./src/sort/custom.c \
			  ./src/sort/insert.c \
			  ./src/checker/valid_number.c \
			  ./src/checker/checker.c

OBJS_SLG	= ${SLG_UTL:.c=.o}

UNAME		:= $(shell uname)

PATH_MLX	= mlx
CC 			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= push_swap

all: 		${NAME}

.c.o:
			${CC} -g ${CFLAGS} -I libft -Imlx -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS) ${OBJS_M} ${OBJS_SLG}
			make -C $(LIBFT)
			${CC} -g $(CFLAGS) -o $(NAME) $(OBJS) ${OBJS_M} ${OBJS_SLG} -L $(LIBFT) -lft

clean:
			make -C $(LIBFT) clean
			${RM} ${OBJS} ${OBJS_M} ${OBJS_SLG}

fclean: 	clean
			make -C $(LIBFT) fclean
			${RM} ${NAME}

re: 		fclean all

test:		all
			./pushswap

val:		all clean
			clear
			valgrind --leak-check=full -q ./push_swap 8 13 44 11 65 38 23 47 41 63 89 20 30 37 14 28 82 19 68 34 43 58 36 95 29 10 83 81 32 22 40 80 71 2 46 73 90 75 48 87 98 85 79 57 9 78 49 93 45 60 61 17 50 51 26 92 18 12 59 4 0 15 96 86 16 24 66 91 54 84 33 52 42 55 70 1 39 62 3 99 35 56 77 76 69 97 72 25 88 74 27 64 7 5 31 6 21 94 67 53 | wc -l

.PHONY:		all gclone clean fclean re test val
