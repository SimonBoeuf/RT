/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:10:40 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/27 19:10:41 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ret;
	int		temp_n;
	size_t	size_ret;
	char	sign;

	sign = (n < 0) ? -1 : 1;
	size_ret = 2 + (n < 0);
	temp_n = n;
	while ((n = n / 10))
		size_ret++;
	n = temp_n;
	if ((ret = (char *)malloc(sizeof(char) * size_ret--)) == NULL)
		return (NULL);
	ret[size_ret--] = '\0';
	ret[size_ret--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		ret[size_ret--] = sign * (n % 10) + '0';
	if (sign < 0)
		ret[size_ret] = '-';
	return (ret);
}
