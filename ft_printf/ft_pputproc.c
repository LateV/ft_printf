/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputproc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:38:38 by vibondar          #+#    #+#             */
/*   Updated: 2018/01/14 16:38:40 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pputproc(t_printf **format)
{
	char *outc;
	char *proc;

	outc = ft_genchar(' ', (*format)->width - 1);
	proc = ft_genchar('%', 1);
	if ((*format)->flag[0] == '-')
		outc = ft_strjoin_free_12(proc, outc);
	else
		outc = ft_strjoin_free_12(outc, proc);
	(*format)->buf = ft_strjoin_free_12((*format)->buf, outc);
}
