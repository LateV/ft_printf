/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:37:22 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:37:24 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <stddef.h>

typedef struct	s_printf
{
	int			invalid;
	int			*zero;
	int			width;
	int			widthdef;
	int			precision;
	int			precisiondef;
	int			sign;
	char		*flag;
	char		*length;
	char		*type;
	char		*buf;
	size_t		num;
}				t_printf;

int				ft_format_flag(int i, char *std_flag,
	char *str, t_printf **format);
int				ft_format_length(int i, char *stdl,
	char *str, t_printf **format);
int				ft_format_precision(int i, t_printf **format, char *str);
int				ft_intnoflagminsneg(t_printf **format, int out, int num);
int				ft_intflagminsneg(t_printf **format, int out, int num);
int				ft_intnoflagmins(t_printf **format, int out, int num);
int				ft_format_width(int i, char *str, t_printf **format);
int				ft_format_type(int i, char *str, t_printf **format);
int				ft_intflagmins(t_printf **format, int out, int num);
int				ft_specif(t_printf **format, char *str, int i);
int				ft_printf(char *str, ...);
int				ft_atoi(const char *str);
int				ft_dig_count(int a);
int				ft_isdigit(int c);

void			ft_intoposnomin_1(t_printf **format, char *outc);
void			ft_intdposnomin_1(t_printf **format, char *outc);
void			ft_intdnegnomin_1(t_printf **format, char *outc);
void			ft_intonegnomin_1(t_printf **format, char *outc);
void			ft_intoposnomin_1(t_printf **format, char *outc);
void			ft_intxposnomin_1(t_printf **format, char *outc);
void			ft_intxposmin_1(t_printf **format, char *outc);
void			ft_intdposmin_1(t_printf **format, char *outc);
void			ft_intdnegmin_1(t_printf **format, char *outc);
void			ft_intoposmin_1(t_printf **format, char *outc);
void			ft_intonegmin_1(t_printf **format, char *outc);
void			ft_pputchar(t_printf **format, va_list argum);
void			ft_pputdnbr(t_printf **format, va_list argum);
void			ft_pputunbr(t_printf **format, va_list argum);
void			ft_pputonbr(t_printf **format, va_list argum);
void			ft_pputxnbr(t_printf **format, va_list argum);
void			ft_pputstr(t_printf **format, va_list argum);
void			ft_putxnolen(t_printf **format, char *outc);
void			ft_putdnolen(t_printf **format, char *outc);
void			ft_putonolen(t_printf **format, char *outc);
void			ft_outp(t_printf *format, va_list argum);
void			ft_pputproc(t_printf **format);
void			ft_freesh(t_printf *format);
void			ft_strtoupper(char *str);
void			ft_putstr(char const *s);
void			ft_putchar(char c);

void			*ft_memset(void *b, int c, size_t len);
void			*ft_bzero(void *b, size_t n);
void			*ft_memalloc(size_t size);

char			*ft_lengtho_nolen(t_printf **format, va_list argum, int base);
char			*ft_lengtho_ll(t_printf **format, va_list argum, int base);
char			*ft_lengtho_hh(t_printf **format, va_list argum, int base);
char			*ft_lengtho_h(t_printf **format, va_list argum, int base);
char			*ft_lengtho_l(t_printf **format, va_list argum, int base);
char			*ft_lengtho_j(t_printf **format, va_list argum, int base);
char			*ft_lengtho_z(t_printf **format, va_list argum, int base);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_lengthu_nolen(t_printf **format, va_list argum);
char			*ft_length_nolen(t_printf **format, va_list argum);
char			*ft_lengthu_ll(t_printf **format, va_list argum);
char			*ft_lengthu_hh(t_printf **format, va_list argum);
char			*ft_itoa_base(unsigned long long num, int base);
char			*ft_length_ll(t_printf **format, va_list argum);
char			*ft_length_hh(t_printf **format, va_list argum);
char			*ft_lengthu_h(t_printf **format, va_list argum);
char			*ft_lengthu_l(t_printf **format, va_list argum);
char			*ft_lengthu_j(t_printf **format, va_list argum);
char			*ft_lengthu_z(t_printf **format, va_list argum);
char			*ft_length_h(t_printf **format, va_list argum);
char			*ft_length_l(t_printf **format, va_list argum);
char			*ft_length_j(t_printf **format, va_list argum);
char			*ft_length_z(t_printf **format, va_list argum);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free_12(char *s1, char *s2);
char			*ft_strjoin_free_10(char *s1, char *s2);
char			*ft_strjoin_free_02(char *s1, char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_genchar_s(char c, int n);
char			*ft_strchr(const char *s, int c);
char			*ft_strtrim(char const *s);
char			*ft_genchar(char c, int n);
char			*ft_strdup(const char *s1);
char			*ft_pitoa(intmax_t n);
char			*ft_genchar_x(t_printf **format);

size_t			ft_strlen(const char *str);

#endif
