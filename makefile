FLAGS= -Wall -Wextra -Werror

SRC := $(addsuffix .c, get_next_line libft/ft_memmove libft/ft_strnew libft/ft_memalloc libft/ft_memcpy libft/ft_bzero libft/ft_memset libft/ft_putchar libft/ft_realloc)

OBJ := $(addsuffix .o, get_next_line libft/ft_memmove libft/ft_strnew libft/ft_memalloc libft/ft_memcpy libft/ft_bzero libft/ft_memset libft/ft_putchar libft/ft_realloc)

RM_OBJ := $(addsuffix .o, get_next_line main ft_memalloc ft_memcpy ft_bzero ft_memset ft_putchar ft_realloc)

NAME= get_next_line

$(NAME):
	@echo "\033[1;32mCompiling Get_Nexl_line..."
	@gcc -g get_next_line.c main.c libft/ft_strlen.c libft/ft_memchr.c libft/ft_memccpy.c libft/ft_memmove.c libft/ft_strnew.c libft/ft_memalloc.c libft/ft_memcpy.c libft/ft_bzero.c libft/ft_memset.c libft/ft_strnlen.c libft/ft_putchar.c libft/ft_realloc.c -o get_next_line

all: $(NAME)

clean:
	@rm -r get_next_line.dSYM && echo "\033[0;32mSussessfully removed get_next_line.dSYM" || echo "\033[0;32mAlready Removed get_next_line.dSYM"
fclean: clean
	@rm get_next_line && echo "\033[0;32mSussessfully removed get_next_line" || echo "\033[0;32mAlready Removed get_next_line"

re: fclean all

