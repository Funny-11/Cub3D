CC = cc

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I.

DEPS = libft.h

NAME = libft.a

SRCS =		./mem/ft_atoi.c \
			./mem/ft_atol.c \
			./mem/ft_itoa.c \
			./mem/ft_bzero.c \
			./mem/ft_calloc.c \
			./ctype/ft_isalnum.c \
			./ctype/ft_isalpha.c \
			./ctype/ft_isascii.c \
			./ctype/ft_isdigit.c \
			./ctype/ft_isprint.c \
			./mem/ft_memchr.c \
			./mem/ft_memcpy.c \
			./mem/ft_memcmp.c \
			./mem/ft_memmove.c \
			./mem/ft_memset.c \
			./ft_printf/ft_putchar_fd.c \
			./ft_printf/ft_putendl_fd.c \
			./ft_printf/ft_putnbr_fd.c \
			./ft_printf/ft_putstr_fd.c \
			./str/ft_strtrim.c \
			./str/ft_striteri.c \
			./str/ft_strmapi.c \
			./str/ft_strchr.c \
			./str/ft_strdup.c \
			./str/ft_strjoin.c \
			./str/ft_strlcat.c \
			./str/ft_strlcpy.c \
			./str/ft_strlen.c \
			./str/ft_strncmp.c \
			./str/ft_strnstr.c \
			./str/ft_strrchr.c \
			./str/ft_substr.c \
			./mem/ft_split.c \
			./ctype/ft_tolower.c \
			./ctype/ft_toupper.c \
			./ft_printf/ft_printf.c \
			./ft_printf/ft_putchar.c \
			./ft_printf/ft_putstr.c \
			./ft_printf/ft_putnbr.c \
			./ft_printf/ft_puthex.c \
			./ft_printf/ft_putptr.c \
			./ft_printf/ft_uputnbr.c \
			./get_next_line/get_next_line_bonus.c \
			./get_next_line/get_next_line_utils_bonus.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
