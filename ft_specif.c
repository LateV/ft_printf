/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:22:31 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/02 14:22:33 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_struct(t_printf **format)
{
	(*format)->flag = (char*)malloc(sizeof(char) * 5);
	ft_memset((*format)->flag, '\0', 5);
	(*format)->width = -1;
	(*format)->precision = -1;
	(*format)->length = (char*)ft_memalloc(sizeof(char) * 2);
	ft_memset((*format)->length, '\0', 2);
	(*format)->type = (char*)ft_memalloc(sizeof(char) * 2);
	ft_memset((*format)->type, '\0', 2);
}

int			ft_specif_fill(t_printf **format, char *str, int i, char *formatic)
{
	while (ft_strchr(formatic, str[i]) != NULL && str[i] != '\0')
	{
		if (ft_strchr("-+#0 ", str[i]) != NULL)
			i = ft_format_flag(i, "-+#0 ", str, format);
		else if (ft_isdigit(str[i]))
			i = ft_format_width(i, str, format);
		else if (str[i] == '.')
			i = ft_format_precision(i, format, str);
		else if (ft_strchr("ljhztL", str[i]) != NULL)
			i = ft_format_length(i, "ljhztL", str, format);
		else
			i++;
	}
	return (i);
}

int			ft_specif(t_printf **format, char *str, int i)
{
	char	*formatic;

	ft_struct(format);
	formatic = ft_strdup(".ljhztL-+#0 123456789");
	i = ft_specif_fill(format, str, i, formatic);
	if (ft_strchr("sSpdDioOuUxXcC", str[i]) != NULL)
		i = ft_format_type(i, str, format);
	else if (str[i] == '%')
	{
		(*format)->type[0] = str[i];
		i++;
	}
	else
	{
		(*format)->type[0] = str[i];
		(*format)->invalid = 1;
	}
	free(formatic);
	return (i);
}
