FLAGS= -g -Wall -Wextra -Werror

SRC := $(addsuffix .c, get_next_line libft/ft_memmove libft/ft_strnew libft/ft_memalloc libft/ft_memcpy libft/ft_bzero libft/ft_memset libft/ft_putchar libft/ft_realloc)

OBJ := $(addsuffix .o, get_next_line libft/ft_memmove libft/ft_strnew libft/ft_memalloc libft/ft_memcpy libft/ft_bzero libft/ft_memset libft/ft_putchar libft/ft_realloc)

RM_OBJ := $(addsuffix .o, get_next_line main ft_memalloc ft_memcpy ft_bzero ft_memset ft_putchar ft_realloc)

NAME= get_next_line

$(NAME):
	@echo "\033[1;32mCompiling Get_Nexl_line..."
	@make -C libft/ fclean && make -C libft/
	@clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	@clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	@clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

all: $(NAME)

clean:
	@rm get_next_line.o;rm main.o
	@rm -r get_next_line.o && rm main.o && echo "\033[0;32mSussessfully removed get_next_line.o and main.o" || echo "\033[0;32mAlready Removed get_next_line.o and main.o"

fclean: clean
	@rm test_gnl && echo "\033[0;32mSussessfully removed test_gnl" || echo "\033[0;32mAlready Removed test_gnl"
	@make -C libft/ fclean

fc: fclean

re: fclean all

