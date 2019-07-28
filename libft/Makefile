NAME=libft.a
CC=gcc
IDIR=include
CFLAGS=-Iinclude -Wall -Werror -Wextra -pedantic-errors $(CFLAGS_SPEED)
CFLAGS_SPEED=-finline-functions -Ofast
DEPS=libft.h

vpath %.c src obj
SRC=$(wildcard src/*)
OBJ=$(SRC:src/%.c=obj/%.o)

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	ar rcs $@ obj/*
	ranlib $(NAME)
	

.PHONY: clean re fclean all
all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) obj/

re : fclean $(NAME)

test: $(NAME)
	$(CC) $(CFLAGS) test.c $(NAME)
	./a.out

norm:
	norminette src/. libft.h