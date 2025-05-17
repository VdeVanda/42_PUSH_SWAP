NAME = push_swap

SRCS = find_stuff.c init_nodes_a.c list_functions.c \
		main.c move_nodes.c push.c reverse_rotate.c \
		rotate.c sort_three.c swap.c syntax_checking.c \
		utils.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I/usr/include -I$(LIBFT_DIR)

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) --no-print-directory -s -C $(LIBFT_DIR) > /dev/null 2>&1
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "PUSH SWAP is ready!!"
	@echo "Usage: ./push_swap \"set of numbers to sort\""

.c.o:
	@$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	@$(MAKE) -s clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS)
	@echo "Files successfully removed."

fclean: clean
	@$(MAKE) -s fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@echo "Goodbye!"

re: fclean all

.PHONY: all clean fclean re
