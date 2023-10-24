##
## EPITECH PROJECT, 2023
## B-CPE-100-LYN-1-1-cpoolday10-max.robert
## File description:
## Makefile
##

SRC	=	$(wildcard	*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	build	mv_lib	cpy_myh

build: $(OBJ)
	ar	rc	$(NAME)	*.o

mv_lib:
	cp	$(NAME)	../

cpy_myh:
	cp	*.h	../../include/

clean:
	rm	-f	$(OBJ)

fclean:	clean
	rm	-f	$(NAME)
