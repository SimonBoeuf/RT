/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <sboeuf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 13:14:09 by sboeuf           #+#    #+#             */
/*   Updated: 2013/11/26 13:14:31 by sboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*temp_s1;

	temp_s1 = s1;
	while (*s1 != '\0')
		s1++;
	while (*s2 != '\0')
		*s1++ = *s2++;
	*s1 = '\0';
	return (temp_s1);
}
