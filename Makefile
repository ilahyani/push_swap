# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 11:47:17 by ilahyani          #+#    #+#              #
#    Updated: 2022/01/18 23:33:40 by ilahyani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	push_swap.c\
		push_swap_utils_1.c\
		push_swap_utils_2.c\
		push_swap_utils_3.c\
		push_swap_moves_1.c\
		push_swap_moves_2.c\

OBJS = $(SRCS:.c=.o)

NAME = push_swap

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

clean:		
			$(RM) $(OBJS) $(LIBFT)/*.o $(LIBFT)/ft_printf/*.o

fclean:		clean
			$(RM) $(NAME) $(LIB)

re:			fclean all