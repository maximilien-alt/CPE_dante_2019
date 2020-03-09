##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	../lib/my/my_putnbr_base.c	\
		../lib/my/my_compute_power_rec.c	\
		../lib/my/my_compute_square_root.c	\
		../lib/my/my_find_prime_sup.c	\
		../lib/my/my_getnbr.c	\
		../lib/my/my_isneg.c	\
		../lib/my/my_is_prime.c	\
		../lib/my/my_putchar.c	\
		../lib/my/my_put_nbr.c	\
		../lib/my/my_putstr.c	\
		../lib/my/my_revstr.c	\
		../lib/my/my_showmem.c	\
		../lib/my/my_showstr.c	\
		../lib/my/my_strcapitalize.c	\
		../lib/my/my_strcat.c	\
		../lib/my/my_strcmp.c	\
		../lib/my/my_strcpy.c	\
		../lib/my/my_strdup.c	\
		../lib/my/my_str_isalpha.c	\
		../lib/my/my_str_islower.c	\
		../lib/my/my_str_isprintable.c	\
		../lib/my/my_str_isupper.c	\
		../lib/my/my_strlen.c	\
		../lib/my/my_strlowcase.c	\
		../lib/my/my_strncat.c	\
		../lib/my/my_strncmp.c	\
		../lib/my/my_strncpy.c	\
		../lib/my/my_strstr.c	\
		../lib/my/my_strupcase.c	\
		../lib/my/my_swap.c	\
		../lib/my/my_delete_neg.c	\
		../lib/my/my_str_is_negative.c	\
		../lib/my/my_str_to_word_array.c	\
		../lib/my/my_supr_same.c	\
		../lib/my/my_mult_zero.c	\
		../lib/my/my_add_x_zero.c	\
		../lib/my/my_delete_mult.c	\
		../lib/my/my_zeroo.c	\
		../lib/my/my_infin_tol.c	\
		../lib/my/my_bistro_error.c	\
		../lib/my/my_occ.c	\
		../lib/my/my_str_isnum.c	\
		../lib/my/my_print_b.c	\
		../lib/my/my_print_c.c	\
		../lib/my/my_print_caps.c	\
		../lib/my/my_print_capx.c	\
		../lib/my/my_print_d.c	\
		../lib/my/my_print_o.c	\
		../lib/my/my_print_p.c	\
		../lib/my/my_print_s.c	\
		../lib/my/my_print_u.c	\
		../lib/my/my_print_x.c	\
		../lib/my/my_printf.c	\
		../lib/my/my_memset.c	\
		../lib/my/get_next_line.c

NAME	=	generator

COMP	=	../src/generator/generator_main.c	\
			../src/generator/dante_generator.c	\
			../src/generator/perfect_map.c	\
			../src/generator/imperfect_map.c	\
			../src/generator/cells.c	\
			../src/generator/check_neighbour.c	\
			../src/generator/random.c	\
			../src/garbage/garbage_collector.c	\

CFLAGS  =	-W -Wall -Wextra -Iinclude -O3

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	: $(OBJ)
	gcc -o $(NAME) $(OBJ) $(COMP) $(CFLAGS)

clean	:
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
