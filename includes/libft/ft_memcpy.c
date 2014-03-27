/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:11:34 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/27 19:11:37 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	void	*temp_s1;

	temp_s1 = s1;
	while (n--)
		*(unsigned char *)s1++ = *(unsigned char *)s2++;
	return (temp_s1);
}
