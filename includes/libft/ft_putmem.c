/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:12:08 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/27 19:12:11 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmem(void *m)
{
	long unsigned int	zero;
	char				size;
	int					toprint;

	zero = 0xF0000000;
	ft_putstr("0x");
	size = sizeof(m);
	while (size-- > 0)
	{
		toprint = (int)(((long unsigned int)m & zero) >> size * 4);
		if (toprint == 0)
			ft_putchar('0');
		else
			ft_putnbr_base(toprint, 16);
		zero = zero >> 4;
	}
}
