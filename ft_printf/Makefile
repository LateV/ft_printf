NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC =	ft_specif.c 	\
		ft_printf.c 	\
		ft_putchar.c 	\
		ft_putstr.c 	\
		ft_strlen.c 	\
		ft_atoi.c 		\
		ft_strchr.c 	\
		ft_isdigit.c 	\
		ft_dig_count.c	\
		ft_memalloc.c 	\
		ft_strdup.c 	\
		ft_bzero.c 		\
		ft_strcpy.c 	\
		ft_outp.c    	\
		ft_pputstr.c 	\
		ft_memset.c 	\
		ft_pputchar.c   \
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

run:
	gcc $(FLAGS) main.c $(NAME) -o ft_printf