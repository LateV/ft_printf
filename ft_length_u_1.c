/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_u_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:39:49 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:39:50 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_lengthu_nolen(t_printf **format, va_list argum)
{
	unsigned int	out;
	char			*outc;

	out = va_arg(argum, unsigned int);
	outc = ft_pitoa(out);
	(*format)->sign = 1;
	return (outc);
}

char	*ft_lengthu_j(t_printf **format, va_list argum)
{
	uintmax_t		out;
	char			*outc;

	out = va_arg(argum, uintmax_t);
	outc = ft_pitoa(out);
	(*format)->sign = 1;
	return (outc);
}

char	*ft_lengthu_z(t_printf **format, va_list argum)
{
	size_t			out;
	char			*outc;

	out = va_arg(argum, size_t);
	outc = ft_pitoa(out);
	(*format)->sign = 1;
	return (outc);
}
