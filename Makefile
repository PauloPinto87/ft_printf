#Variaveis
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -Ilibft
AR = ar rcs
RM = rm -f

SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C libft clean

fclean:
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

libft/libft.a:
	$(MAKE) -C libft