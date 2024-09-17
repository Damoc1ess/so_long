# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIE -Iincludes
SRC_DIR = src
SRCS = $(wildcard $(SRC_DIR)/*/*.c)
OBJS = $(SRCS:.c=.o)
AR = ar rcs

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus
.SILENC:
