/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <sboeuf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:21:16 by sboeuf           #+#    #+#             */
/*   Updated: 2013/11/22 17:21:15 by sboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	while (n--)
	{
		*(unsigned char *)s1++ = *(unsigned char *)s2;
		if (*(unsigned char *)s2 == (unsigned char)c)
			return (s1);
		s2++;
	}
	return (NULL);
}
