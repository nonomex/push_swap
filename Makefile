NAME	= push_swap

SRCS	= push_swap.c \
				sorting.c \
				splitint.c \
				utils.c \
				utils2.c \
				sorting2.c \
				utils3.c

CC 		= cc

CFLAGS	= -Wextra -Wall -Werror 

OBJS 	= $(SRCS:.c=.o)

HEADERS	= push_swap.h

%.o : %.c ${HEADERS} Makefile
	${CC} ${CFLAGS} -c $< -o $@ -I $(HEADERS)

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}

all: ${NAME}

clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean re
