NAME = ft_nm
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

SRCS = srcs/main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Compilation complete ✅"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -s -C libft

clean:
	@rm -rf $(OBJS)
	@$(MAKE) -s -C libft clean
	@echo "Cleaning objects 🧹"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -s -C libft fclean
	@echo "Full clean 🧼"

re: fclean all

.PHONY: all clean fclean re