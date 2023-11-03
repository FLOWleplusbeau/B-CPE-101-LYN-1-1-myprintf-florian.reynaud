##
## EPITECH PROJECT, 2023
## B-CPE-101-LYN-1-1-myprintf-florian.reynaud
## File description:
## Makefile
##

SRC	=	my_printf.c	\
	flags/do_flag_e.c	\
	put/my_put_float.c	\
	put/my_putnbr_base.c	\
	put/my_put_nbr.c	\
	put/my_putchar.c	\
	put/my_putstr.c	\
	utility/my_strlen.c	\
	utility/my_strncpy.c	\
	check/is_special_char.c	\
	utility/my_str_add.c	\
	utility/give_flag.c	\
	put/put_l.c	\
	flags/do_flag.c	\
	flags/do_flags.c	\
	check/my_char_is_num.c	\
	check/my_char_is_in_str.c	\
	flags/do_flag_base.c	\
	utility/give_nb_char.c	\
	utility/my_getnbr.c	\
	utility/give_precision.c	\
	length_put/length_put.c	\
	length_put/length_putnbr_base.c	\
	utility/fill_flag.c	\
	utility/get_attribut.c	\
	put/put_operator.c	\
	length_put/length_put_float.c	\
	length_put/length_flag_e.c	\
	flags/do_flag_f.c	\
	flags/do_flag_g.c	\
	flags/do_flag_n.c
	utility/get_length_modifier.c	\
	flags/do_flag_d.c	\


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	libmy.a

libmy.a:	mv_obj
	ar	rc	$(NAME)	objects/*.o

mv_obj:	$(OBJ)
	mv $(OBJ) objects/

clean:
	rm -f objects/*.o

fclean:	clean
	rm -f	$(NAME)

re:	fclean	libmy.a
