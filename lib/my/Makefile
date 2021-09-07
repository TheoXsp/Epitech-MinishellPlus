##
## EPITECH PROJECT, 2020
## Makefile lib
## File description:
## Builds the lib.
##

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

INCLUDE = mkdir -p ../../include && cp *.h ../../include

NAME = libmy.a

all : $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) && mv $(NAME) ../ && $(INCLUDE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
