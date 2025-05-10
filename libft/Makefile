SRCS =	ft_bzero.c \
		ft_calloc.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_split.c \
		ft_strchr.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_substr.c \
		ft_utoa.c
OBJS	= $(SRCS:.c=.o)
NAME	= libft.a
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean	all

.PHONY:	all clean fclean re