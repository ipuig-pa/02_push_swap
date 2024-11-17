NAME = push_swap
BONUS_NAME = checker

CFLAGS = -Wall -Wextra -Werror

SOURCES = 	push_swap.c \
			push_swap_stack_creation.c \
			push_swap_sort.c \
			push_swap_exec_and_print.c \
			push_swap_commands.c \
			push_swap_helper.c \
			push_swap_helper_two.c \
			push_swap_stack_tools.c

BONUS_SOURCES = push_swap_checker_bonus.c \
				push_swap_stack_creation.c \
				push_swap_sort.c \
				push_swap_exec_and_print.c \
				push_swap_commands.c \
				push_swap_helper.c \
				push_swap_stack_tools.c

OBJECTS = $(SOURCES:.c=.o)
HEADER = push_swap.h

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)
BONUS_HEADER = push_swap_bonus.h

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all : $(NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJECTS) $(LIBFT) $(BONUS_HEADER)
	cc $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJECTS) $(LIBFT)

$(NAME) : $(OBJECTS) $(LIBFT) $(HEADER)
	cc $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

$(LIBFT) : 
	make -C $(LIBFT_DIR)

%o: %.c $(HEADER)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus