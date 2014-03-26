/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 19:17:47 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/26 21:14:19 by wtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

t_cylinder	*new_cylinder(t_vect *pos, double r, t_color *col, t_vect *axis)
{
	t_cylinder	*c;

	c = (t_cylinder*)malloc(sizeof(t_cylinder));
	c->center = pos;
	c->radius = r;
	c->axis = axis;
	c->color = col;
	c->next = NULL;
	return (c);
}

void		add_cylinder(t_cylinder *start, t_cylinder *new)
{
	while (start->next != NULL)
		start = start->next;
	start->next = new;
}

void		delete_cylinders(t_cylinder **start)
{
	t_cylinder	*tmp;

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
