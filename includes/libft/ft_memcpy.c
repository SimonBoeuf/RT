/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <sboeuf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:02:35 by sboeuf           #+#    #+#             */
/*   Updated: 2013/11/23 13:59:04 by sboeuf          ###   ########.fr       */
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
