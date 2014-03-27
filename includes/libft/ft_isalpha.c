/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:10:19 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/27 19:10:21 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (((unsigned int)c >= 'A' && (unsigned int)c <= 'Z')
			|| ((unsigned int)c >= 'a' && (unsigned int)c <= 'z'))
		return (1);
	else
		return (0);
}
