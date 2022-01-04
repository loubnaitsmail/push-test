CC = gcc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
INC = -I./includes
SRCS =			srcs/operations.c \
				srcs/operations_2.c \
				srcs/operations_3.c \
				srcs/functions.c \
				srcs/trie.c \
				srcs/main.c \

OBJS =			${SRCS:.c=.o}

.c.o :
	${CC} ${CFLAGS} -c ${INC} $< -o ${<:.c=.o}

${NAME} : ${LIBFT} ${OBJS}
	ar rc ${NAME} ${OBJS} $(shell find libft -name '*.o')
	ranlib ${NAME}

${LIBFT} :
	make all -C libft

all : ${NAME}

clean :
	make clean -C libft
	rm -f  ${OBJS}

fclean : clean
	make fclean -C libft
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
