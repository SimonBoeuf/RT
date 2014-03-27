/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <sboeuf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:39:58 by sboeuf           #+#    #+#             */
/*   Updated: 2013/11/20 16:11:13 by sboeuf          ###   ########.fr       */
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
