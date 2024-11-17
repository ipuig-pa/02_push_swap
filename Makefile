NAME = push_swap
BONUS_NAME = checker

CFLAGS = -Wall -Wextra -Werror

SOURCES = 	push_swap.c \
			push_swap_stack_creation.c \
			push_swap_sort.c \
			push_swap_exec_and_print.c \
			push_swap_commands.c \
			push_swap_helper.c \
			push_swap_stack_tools.c

BONUS_SOURCES = checker_bonus.c

OBJECTS = $(SOURCES:.c=.o)
HEADER = push_swap.h

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

#get next line, ft printf, bonus, etc

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
	cc $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

$(LIBFT) : 
	make -C $(LIBFT_DIR)

%o: %.c $(HEADER)
	cc $(CFLAGS) -c $< -o $@

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS) $(NAME)


clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re