SRCS =	ft_printf.c \
		formats/ft_print_char.c \
		formats/ft_print_hex_lower.c \
		formats/ft_print_hex_upper.c \
		formats/ft_print_int.c \
		formats/ft_print_percent.c \
		formats/ft_print_pointer.c \
		formats/ft_print_string.c \
		formats/ft_print_unsigned.c \
		formats/ft_print_utils.c
OBJS	= $(SRCS:.c=.o)
NAME	= libftprintf.a

LIBFT_DIR = ../libft
LIBFT_A = $(LIBFT_DIR)/libft.a

CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT_A) $(OBJS)
	cp $(LIBFT_A) $(NAME)
	ar rcs $(NAME) $(OBJS) *.o

all: $(LIBFT_A) $(NAME)

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