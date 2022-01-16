
SRCS =	push_swap.c\
		push_swap_utils_1.c\
		push_swap_utils_2.c\
		push_swap_utils_3.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

$(NAME):	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:		$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all