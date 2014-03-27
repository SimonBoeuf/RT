/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 18:57:51 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/27 18:58:09 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

void	check_cylinders(void)
{
	t_cylinder	*c;

	c = get_scene()->cylinders;
	while (c != NULL)
	{
		if (c->center == NULL || c->color == NULL || c->axis == NULL
			|| c->upper == NULL)
		{
			ft_putendl("Invalid cylinder");
			exit(-1);
		}
		c = c->next;
	}
}
