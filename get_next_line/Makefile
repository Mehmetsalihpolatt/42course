SRCS = get_next_line.c get_next_line_utils.c

BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c 

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

NAME = get_next_line.a

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: ${BONUS_OBJS}
	ar -rcs bonus.a ${BONUS_OBJS}

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re:	fclean all bonus