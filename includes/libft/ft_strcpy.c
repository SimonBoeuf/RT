/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:12:44 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/27 19:12:47 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	char	*temp_s1;

	temp_s1 = s1;
	while (*s2 != '\0')
		*s1++ = *s2++;
	*s1 = '\0';
	return (temp_s1);
}
