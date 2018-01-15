/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:37:35 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:37:37 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(t_printf **format)
{
	size_t	num;

	num = (*format)->num + ft_strlen((*format)->buf);
	write(1, (*format)->buf, ft_strlen((*format)->buf));
	free((*format)->buf);
	return (num);
}

static int	ft_outforstr(char *str, int i, t_printf **format)
{
	int		j;
	char	*tmp;
	char	*s2;

	j = i;
	tmp = (*format)->buf;
	while (str[i] != '%' && str[i] != '\0')
		i++;
	s2 = ft_strsub(str, j, i - j);
	(*format)->buf = ft_strjoin((*format)->buf, s2);
	free(tmp);
	free(s2);
	return (i);
}

static void	ft_highwaytohell(char *str, int i, t_printf **format)
{
	int		j;
	char	*tmp;
	char	*s2;

	j = i;
	tmp = (*format)->buf;
	while (str[i] != '\0')
		i++;
	s2 = ft_strsub(str, j, i - j);
	(*format)->buf = ft_strjoin((*format)->buf, s2);
	free(tmp);
	free(s2);
}

static int	ft_loop(char *str, int i, t_printf **format, va_list argum)
{
	while (str[i] != '\0')
	{
		if ((*format)->invalid == 0 && str[i] != '%')
			i = ft_outforstr(str, i, format);
		else if ((*format)->invalid == 1)
		{
			ft_highwaytohell(str, i, format);
			break ;
		}
		if (str[i] == '%')
		{
			i = ft_specif(format, str, i + 1);
			if ((*format)->invalid == 1)
				continue ;
			ft_outp((*format), argum);
			ft_freesh((*format));
		}
	}
	return (i);
}

int			ft_printf(char *str, ...)
{
	va_list			argum;
	static t_printf	*format;
	int				i;
	int				k;

	i = 0;
	format = malloc(sizeof(t_printf));
	format->buf = ft_strdup("");
	format->invalid = 0;
	va_start(argum, str);
	i = ft_loop(str, i, &format, argum);
	va_end(argum);
	k = ft_print(&format);
	free(format);
	return (k);
}
