# Main var

NAME = fillit

SHELL = /bin/zsh
# GCC

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -I libft/includes -I .

# Sources & Objects
SRCS =	main.c \
		errors.c \
		parser.c \
		map.c \
		tetri_modifier.c \
		solver.c \

OBJS = $(patsubst %.c, %.o, $(SRCS))

# Includes

INCLUDES = -L libft/ -lft

# Utils
RM = rm -rf
LIBFT = libft/

# Compiling & other stuff

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS) fillit.h
	@make -C $(LIBFT)
	@echo -n "\e[1;36m Compiling $@...\e[0m"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES)
	@echo "\e[1;32mOK!\e[0m"

%.o : %.c
	@echo -n "\e[1;36m Compiling $<..\e[0m"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\e[1;32mOK!\e[0m"

clean :
	@echo "\e[1;33m Cleaning fillit objects files... \e[0m"
	@$(RM) $(OBJS)
	@make clean -C libft/
fclean : clean
	@echo "\e[1;33m Cleaning $(NAME). \e[0m"
	@$(RM) $(NAME)
	@make fclean -C libft/

re : fclean all

.PHONY : all clean fclean re
