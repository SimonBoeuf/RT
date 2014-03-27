/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 19:17:47 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/27 19:33:27 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

t_cone		*new_cone(t_vect *center, double alpha, t_color *col, t_vect *axis)
{
	t_cone	*c;

	c = (t_cone*)malloc(sizeof(t_cone));
	c->center = center;
	c->alpha = alpha;
	c->axis = axis;
	c->color = col;
	c->upper = NULL;
	c->lower = NULL;
	c->cos2 = pow(cos(alpha), 2);
	c->sin2 = pow(sin(alpha), 2);
	return (c);
}

void		calc_trigo(t_cone *c)
{
	c->sin2 = pow(sin(c->alpha), 2);
	c->cos2 = pow(cos(c->alpha), 2);
}

void		add_cone(t_cone *start, t_cone *new)
{
	while (start->next != NULL)
		start = start->next;
	start->next = new;
}

void		delete_cones(t_cone **start)
{
	t_cone	*tmp;

	while (*start != NULL)
	{
		tmp = (*start)->next;
		delete_vect((*start)->center);
		delete_color((*start)->color);
		delete_vect((*start)->axis);
		(*start)->next = NULL;
		free(*start);
		*start = tmp;
	}
}
