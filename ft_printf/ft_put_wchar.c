/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:07:14 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/01/10 17:07:15 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_wchar2(wchar_t chr)
{
	if (chr <= 65535)
	{
		ft_putchar((chr >> 12) + 0b11100000);
		ft_putchar(((chr >> 6) & 0b111111) + 0b10000000);
		ft_putchar((chr & 0b111111) + 0b10000000);
		return (3);
	}
	else if (chr <= 1114111)
	{
		ft_putchar((chr >> 18) + 0b11110000);
		ft_putchar(((chr >> 12) & 0b111111) + 0b10000000);
		ft_putchar(((chr >> 6) & 0b111111) + 0b10000000);
		ft_putchar((chr & 0b111111) + 0b10000000);
		return (4);
	}
	else
		return (0);
}

int			ft_put_wchar(wchar_t chr)
{
	if (chr <= 127)
	{
		ft_putchar(chr);
		return (1);
	}
	else if (chr <= 2047)
	{
		ft_putchar((chr >> 6) + 0b11000000);
		ft_putchar((chr & 0b111111) + 0b10000000);
		return (2);
	}
	else
		return (ft_put_wchar2(chr));
}
