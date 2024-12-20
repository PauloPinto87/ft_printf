#Variaveis
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -Ilibft
AR = ar rcs
RM = rm -f

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	@cp libft/libft.a $(NAME)
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