FLAGS= -Wall -Wextra -Werror

SRC := $(addsuffix .c, get_next_line libft/ft_isprint libft/ft_memalloc libft/ft_memcpy libft/ft_bzero libft/ft_memset libft/ft_putchar libft/ft_realloc)

OBJ := $(addsuffix .o, get_next_line libft/ft_isprint libft/ft_memalloc libft/ft_memcpy libft/ft_bzero libft/ft_memset libft/ft_putchar libft/ft_realloc)

RM_OBJ := $(addsuffix .o, get_next_line main ft_memalloc ft_memcpy ft_bzero ft_memset ft_putchar ft_realloc)

NAME= get_next_line

$(NAME):
	@echo "\033[1;32mCompiling Get_Nexl_line..."
	@gcc get_next_line.c main.c libft/ft_isprint.c libft/ft_memalloc.c libft/ft_memcpy.c libft/ft_bzero.c libft/ft_memset.c libft/ft_putchar.c libft/ft_realloc.c -o get_next_line

all: $(NAME)

clean:
	rm get_next_line
fclean: clean

re: fclean all

