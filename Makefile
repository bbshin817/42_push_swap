SRCS =	main.c
OBJS	= $(SRCS:.c=.o)
NAME	= push_swap

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

all: $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:	fclean	all

.PHONY:	all clean fclean re