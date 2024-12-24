##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC	=	$(shell find *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

copy:
	mv my.h ../../include/
	mv libmy.a ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
