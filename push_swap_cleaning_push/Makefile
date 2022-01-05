 
NAME	=	push_swap
 
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g
IFLAGS	=	-I. -I./libft -I includes
LFLAGS	=	-L./libft -lft
BFLAGS	=	0
 
SRC	=			srcs/main.c \
					srcs/operations.c \
					srcs/operations_2.c \
					srcs/operations_3.c \
					srcs/functions.c \
					srcs/trie.c \
					srcs/small_sort.c

OBJ		=	$(SRC:%.c=%.o)
 
%.o: %.c
			$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ -D BONUS=$(BFLAGS)
 
ifeq ($(shell uname), Linux)
$(NAME): IFLAGS = -I. -I./libft
endif
 
$(NAME):	$(OBJ)
			$(MAKE) -C libft
			$(CC) $(CFLAGS) $(OBJ) $(IFLAGS) $(LFLAGS) -o $@
 
 
all:		$(NAME)
 
bonus:		BFLAGS = 1
bonus:		$(NAME)
 
clean:
			$(MAKE) -C libft clean
			rm -rf $(OBJ)
 
ifeq ($(shell uname), Linux)
endif
 
fclean:		clean
			$(MAKE) -C libft fclean
			rm -rf $(NAME)
 
re:			fclean all
 
.PHONY: all clean fclean re
 
