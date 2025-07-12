SRCS =			src/push_swap/main.c \
				src/push_swap/sort/sort.c \
				src/push_swap/sort/sort_over_five.c \
				src/push_swap/sort/sort_over_five_2.c \
				src/push_swap/operation/push.c \
				src/push_swap/operation/rotate.c \
				src/push_swap/operation/reverse_rotate.c \
				src/push_swap/operation/swap.c \
				src/push_swap/utils/validation.c \
				src/push_swap/utils/append.c \
				src/push_swap/utils/print.c \
				src/push_swap/utils/free.c \
				src/push_swap/utils/count.c \
				src/push_swap/utils/command.c \
				src/push_swap/utils/ex_atoi.c

BONUS_SRCS	=	src/checker/main.c \
				src/checker/errors.c \
				src/checker/stack.c \
				src/checker/node.c \
				src/checker/command.c \
				src/checker/ex_atoi.c \
				src/checker/free.c \
				src/checker/validation.c \
				get_next_line/get_next_line_utils.c \
				get_next_line/get_next_line.c

OBJS	= $(SRCS:.c=.o)
NAME	= push_swap

BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
BONUS_NAME	= checker

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

PRINTF_DIR = printf
PRINTF_A = $(PRINTF_DIR)/libftprintf.a

CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT_A) $(PRINTF_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(PRINTF_A) -o $(NAME)

$(BONUS_NAME): $(LIBFT_A) $(PRINTF_A) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_A) $(PRINTF_A) -o $(BONUS_NAME)

all: $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_A):
	$(MAKE) -C $(PRINTF_DIR)

bonus: $(BONUS_NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean:	clean
	$(RM) $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re:	fclean	all

.PHONY:	all clean fclean re bonus