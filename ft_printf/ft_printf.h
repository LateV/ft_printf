#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
//
# include <fcntl.h>
# include <stdio.h>
//


typedef struct	s_printf
{
	char		*flag;
	int			width;
	int			precision;
	char		*length;
	char		*type;
}				t_printf;


int				ft_pputchar(t_printf **format, va_list argum, int num);
int 			ft_pputstr(t_printf **format, va_list argum, int num);
int 			ft_outp(t_printf *format, va_list argum, int num);
int 			ft_specif(t_printf **format, char *str, int i);
int 			ft_printf(char *str, ...);
int				ft_atoi(const char *str);
int				ft_dig_count(int a);
int				ft_isdigit(int c);

void			ft_putstr(char const *s);
void			ft_putchar(char c);


void			*ft_memset(void *b, int c, size_t len);
void			*ft_bzero(void *b, size_t n);
void			*ft_memalloc(size_t size);


char			*ft_strcpy(char *dst, const char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);

size_t			ft_strlen(const char *str);

#endif