/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:13:58 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/27 19:14:01 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*temp_s1;
	const char	*temp_s2;

	temp_s2 = s2;
	if (*temp_s2 == '\0')
		return ((char *)s1);
	while (*s1 != '\0')
	{
		if (*s1 == *temp_s2)
		{
			temp_s1 = s1;
			while (1)
			{
				if (*temp_s2 == '\0')
					return ((char *)s1);
				if (*temp_s1++ != *temp_s2++)
					break ;
			}
			temp_s2 = s2;
		}
		s1++;
	}
	return (NULL);
}
