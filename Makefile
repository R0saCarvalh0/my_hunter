##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC		=	main.c	\
			sources/my_hunter.c	\
			sources/menu.c	\
			sources/end.c	\
			sources/mouse.c	\
			sources/destroy.c	\
			sources/level.c	\
			sources/display.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS	=	-I./include/

GRAPHICS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:    $(NAME)

$(NAME):
	make -C lib/my/
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(GRAPHICS) -L lib/my/ -lmy $(WFLAGS)

test:
	gcc -o $(NAME) $(SRC) -I include/ -L lib/my/ -lmy --coverage -lcriterion

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: all test clean fclean re
