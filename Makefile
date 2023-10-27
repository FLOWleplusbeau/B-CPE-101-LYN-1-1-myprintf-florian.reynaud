##
## EPITECH PROJECT, 2023
## B-CPE-101-LYN-1-1-myprintf-florian.reynaud
## File description:
## Makefile
##

SRC	=	my_printf.c	\
	my_put_flagE.c	\
	my_put_float.c	\
	my_putnbr_base.c	\
	my_put_nbr.c	\
	my_putchar.c	\
	my_putstr.c	\
	my_strlen.c	\
	my_strncpy.c	\
	is_special_char.c	\
	my_str_add.c	\
	give_flag.c	\
	put_l.c	\
	do_flag.c	\
	do_flags.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	libmy.a

libmy.a:	$(OBJ)
	mv $(OBJ) ./binary
	ar	rc	$(NAME)	binary/*.o

mv_obj:
	mv $(OBJ) ./

clean:
	rm -f	$(OBJ)

fclean:	clean
	rm -f	$(NAME)

re:	fclean	libmy.a
