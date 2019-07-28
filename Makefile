CC=gcc
CFLAGS=-Werror -Wextra -Wall -g -Iinclude -Ilibft/include
LIB=-Llibft -lft
LIBFT=libft/libft.a
FRAMEWORK=
COMMON_SRC=$(shell find src/common -type f -name '*.c')
NM_SRC=$(shell find src/ft_nm -type f -name '*.c')
OTOOL_SRC=$(shell find src/ft_otool -type f -name '*.c')
SRC=$(shell find src -type f -name '*.c')
COMMON_OBJ=$(COMMON_SRC:src/common/%.c=obj/common/%.o)
NM_OBJ=$(NM_SRC:src/%.c=obj/%.o)
OTOOL_OBJ=$(OTOOL_SRC:src/%.c=obj/%.o)
OBJ=$(SRC:src/%.c=obj/%.o)
NM=ft_nm
OTOOL=ft_otool

all: $(NM) $(OTOOL)

$(NM): $(NM_OBJ) $(COMMON_OBJ)
	$(CC) $(CFLAGS) $(LIB) -o $(NM) $(NM_OBJ) $(COMMON_OBJ)
	echo "$(NM) build complete!"

$(OTOOL): $(OTOOL_OBJ) $(COMMON_OBJ)
	$(CC) $(CFLAGS) $(LIB) -o $(OTOOL) $(OTOOL_OBJ) $(COMMON_OBJ)
	echo "$(OTOOL) build complete!"

$(NM_OBJ): obj/ft_nm/%.o : src/ft_nm/%.c
	@mkdir -p $(shell dirname $@) 
	$(CC) $(CFLAGS) -o $@ -c $^

$(OTOOL_OBJ): obj/ft_otool/%.o : src/ft_otool/%.c
	@mkdir -p $(shell dirname $@) 
	$(CC) $(CFLAGS) -o $@ -c $^

$(COMMON_OBJ): obj/common/%.o : src/common/%.c
	@mkdir -p $(shell dirname $@) 
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	@rm -rf obj/

fclean: clean
	@rm -f $(NM) $(OTOOL)

re: fclean all
