/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:39:05 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:39:07 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_outp(t_printf *format, va_list argum)
{
	if (format->type[0] == 's')
		ft_pputstr(&format, argum);
	if (format->type[0] == 'c')
		ft_pputchar(&format, argum);
	if (format->type[0] == 'd' || format->type[0] == 'i')
		ft_pputdnbr(&format, argum);
	if (format->type[0] == 'D')
		ft_putdnolen(&format, ft_length_l(&format, argum));
	if (format->type[0] == 'u')
		ft_pputunbr(&format, argum);
	if (format->type[0] == 'U')
		ft_putdnolen(&format, ft_lengthu_l(&format, argum));
	if (format->type[0] == 'o')
		ft_pputonbr(&format, argum);
	if (format->type[0] == 'x' || format->type[0] == 'X')
		ft_pputxnbr(&format, argum);
	if (format->type[0] == '%')
		ft_pputproc(&format);
	if (format->type[0] == 'S')
		ft_pputstr(&format, argum);
	if (format->type[0] == 'C')
		ft_pputstr(&format, argum);
}
