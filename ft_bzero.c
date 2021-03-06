/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:41:38 by vibondar          #+#    #+#             */
/*   Updated: 2017/10/26 15:41:39 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_bzero(void *b, size_t n)
{
	unsigned char	*i;
	size_t			j;

	i = (unsigned char *)b;
	j = 0;
	while (j < n)
	{
		i[j] = 0;
		j++;
	}
	return (b);
}
