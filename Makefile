NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC =	ft_specif.c 			\
		ft_printf.c 			\
		ft_putchar.c 			\
		ft_putstr.c 			\
		ft_strlen.c 			\
		ft_atoi.c 				\
		ft_strchr.c 			\
		ft_isdigit.c 			\
		ft_dig_count.c			\
		ft_memalloc.c 			\
		ft_strdup.c 			\
		ft_bzero.c 				\
		ft_strcpy.c 			\
		ft_outp.c    			\
		ft_pputstr.c 			\
		ft_memset.c 			\
		ft_pputchar.c   		\
		ft_format.c 			\
		ft_pputdnbr.c 			\
		ft_pitoa.c 				\
		ft_freesh.c 			\
		ft_pputproc.c   		\
		ft_strsub.c         	\
		ft_strjoin.c 			\
		ft_strcat.c  			\
		ft_strncpy.c  			\
		ft_genchar.c 			\
		ft_strjoin_free_12.c 	\
		ft_putdnolen.c      	\
		ft_intdnegmin_1.c 		\
		ft_intdposmin_1.c   	\
		ft_intdnegmin_1.c   	\
		ft_intdposnomin_1.c 	\
		ft_intdnegnomin_1.c 	\
		ft_length.c 			\
		ft_length_1.c 			\
		ft_length_u.c 			\
		ft_length_u_1.c 		\
		ft_strtrim.c    		\
		ft_itoa_base.c 			\
		ft_putonolen.c 			\
		ft_putxnolen.c 			\
		ft_intoposnomin_1.c  	\
		ft_intxposnomin_1.c  	\
		ft_intoposmin_1.c 		\
		ft_intxposmin_1.c 		\
		ft_length_o.c 			\
		ft_length_o_1.c 		\
		ft_strtoupper.c  		\


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
	gcc main.c $(NAME) -o ft_printf
	./ft_printf | cat -e