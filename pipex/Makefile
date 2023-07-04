NAME    = pipex

CC				= cc -g

# CFLAGS			= -Wall -Werror -Wextra                                                             

SRC     = main.c srcs/libft_functs.c srcs/ft_split.c srcs/path.c srcs/processes.c

OBJ     = main.o srcs/libft_functs.o srcs/ft_split.o srcs/path.o srcs/processes.o

all:    $(NAME)

$(NAME): $(OBJ)
		$(CC) $(SRC) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
