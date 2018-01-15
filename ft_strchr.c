/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:02:32 by vibondar          #+#    #+#             */
/*   Updated: 2017/11/01 12:02:38 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;

	str = (unsigned char*)s;
	while (*str || c == '\0')
	{
		if (*str == c)
			return ((char*)str);
		str++;
	}
	return (0);
}
