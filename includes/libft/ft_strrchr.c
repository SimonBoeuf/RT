/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:13:47 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/27 19:13:50 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*temp_s;

	temp_s = s;
	temp_s = temp_s + ft_strlen(s);
	while (*temp_s != (char)c && temp_s != s)
		temp_s--;
	if (*temp_s == (char)c)
		return ((char *)temp_s);
	return (NULL);
}
