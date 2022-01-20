# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 11:47:17 by ilahyani          #+#    #+#              #
#    Updated: 2022/01/19 18:41:13 by ilahyani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	push_swap.c\
		push_swap_utils_1.c\
		push_swap_utils_2.c\
		push_swap_utils_3.c\
		push_swap_moves_1.c\
		push_swap_moves_2.c\
		push_swap_moves_3.c

BNS_SRCS =	bonus/checker.c\
			bonus/checker_utils.c\
			bonus/checker_utils_2.c\
			bonus/moves_1.c\
			bonus/moves_2.c\
			bonus/moves_3.c\

OBJS = $(SRCS:.c=.o)

BNS_OBJS = $(BNS_SRCS:.c=.o)

NAME = push_swap

BNS_NAME = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT = ./libft

LIB = ./libft/libft.a

$(NAME):	$(OBJS) $(LIB)
			$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

all:		$(NAME)

$(LIB):
			Make -C $(LIBFT)

bonus:		$(BNS_OBJS) $(LIB)
			$(CC) $(CFLAGS) $(BNS_OBJS) $(LIB) -o $(BNS_NAME)

clean:		
			$(RM) $(OBJS) $(BNS_OBJS) $(LIBFT)/*.o $(LIBFT)/ft_printf/*.o $(LIBFT)/get_next_line/*.o

fclean:		clean
			$(RM) $(NAME) $(BNS_NAME) $(LIB)

re:			fclean all