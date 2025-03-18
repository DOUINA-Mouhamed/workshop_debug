
CC = gcc
SRC = 	main.c			\
	string.c		\
	str_to_word_array.c	\

OBJ = $(SRC:.c=.o)
TARGET = test

all: $(OBJ)
	gcc $(OBJ) -o $(TARGET) -fsanitize=address -lasan

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -c -g3 -Werror

fclean: clean
	rm $(TARGET)

clean:
	rm $(OBJ)

re : fclean all

.phony: all clean fclean re
