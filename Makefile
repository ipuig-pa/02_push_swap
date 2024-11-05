NAME = push_swap.a

CFLAGS = -Wall -Wextra -Werror
SOURCES = 

OBJECTS = $(SOURCES: .c=.o)
HEADER = push_swap.h

//libft make!!!!!

all : $(NAME) $(LIBFT)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%o. : %.c $(HEADER)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm - f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

PHONY all clean fclean re