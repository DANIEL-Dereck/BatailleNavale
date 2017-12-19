##
## Makefile for makefile in /home/daniel_d/Name_Prog
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Sun Mar  9 23:33:38 2014 daniel_d
## Last update Fri Aug 12 10:14:48 2016 daniel_d
##

CC 	= gcc

RM	= rm -f

LNAME	= lib/libmy.a
NAME	= BatailleNaval

CFLAGS	+= -Wall -Wextra
CFLAGS	+= -I include/ -L lib -lmy

SRC	= src/ww_ask.c \
	src/ww_game.c \
	src/ww_play.c \

LSRC	= lib/my/string/get_next_line.c \
        lib/my/string/my_strcat.c \
	lib/my/string/my_epur_str.c \
        lib/my/string/my_needposchar.c \
	lib/my/string/my_nmatch.c \
	lib/my/string/my_putchar.c \
        lib/my/string/my_putstr.c \
        lib/my/string/my_revstr.c \
        lib/my/string/my_strcmp.c \
        lib/my/string/my_strdup.c \
	lib/my/string/my_strlen.c \
        lib/my/string/my_str_to_wordtab.c \
        lib/my/number/my_put_nbr.c \
        lib/my/number/my_put_nbr_rec.c \
        lib/my/number/my_putnbr_base.c \
        lib/my/number/my_putnbr_base_rec.c \
        lib/my/number/my_put_nbru.c \
        lib/my/number/my_getnbr.c \
	lib/my/number/my_pow.c \
        lib/my/my_printf/my_printf.c \
        lib/my/my_printf/my_format.c \
        lib/my/my_printf/my_format2.c \
        lib/my/my_printf/my_format3.c \

OBJ	= $(SRC:.c=.o)

LOBJ	= $(LSRC:.c=.o)

all	: $(LNAME) $(NAME)

$(LNAME)	: $(LOBJ)
	@ar rc $(LNAME) $(LOBJ)
	@cp lib/my/my.h include/
	@echo -e "\033[32m<####################\033[36mCompilation lib\033[32m####################>\033[0m"

$(NAME)	: $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
	@echo -e "\033[32m<####################\033[36mCompilation\033[32m####################>\033[0m"

clean	:
	@$(RM) $(OBJ)
	@$(RM) $(LOBJ)
	@echo -e "\033[32m<####################\033[36mmake clean\033[32m####################>\033[0m"

fclean	: clean
	@$(RM) $(NAME)
	@$(RM) $(LNAME)
	@echo -e "\033[32m<####################\033[36mmake fclean\033[32m####################>\033[0m"

re	: fclean all
	@echo -e "\033[32m<####################\033[36mmake re\033[32m####################>\033[0m"

exe	: all clean
	@echo -e "\033[32m<####################\033[36mmake exe\033[32m####################>\033[0m"
