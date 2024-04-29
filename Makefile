SRCS = ${wildcard *.c}
OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs 
RM = rm -rf

all : ${NAME}

${NAME} : ${OBJS}
	${AR} ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re