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
			  ./src/order.c \
			  ./src/moves/moves.c \
			  ./src/moves/moves_a.c \
			  ./src/moves/moves_b.c \
			  ./src/moves/moves_s.c \
			  ./src/sort/radix.c \
			  ./src/sort/custom.c \
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

.PHONY:		all clean fclean re
