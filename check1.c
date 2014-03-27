/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 18:56:44 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/27 18:57:44 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

void	check_camera(void)
{
	t_camera	*c;

	c = get_scene()->cam;
	if (c->campos == NULL || c->camdir == NULL || c->camright == NULL ||
			c->camdown == NULL)
	{
		ft_putendl("Invalid camera");
		exit(-1);
	}
}

void	check_lights(void)
{
	t_light		*l;

	l = get_scene()->lights;
	while (l != NULL)
	{
		if (l->position == NULL || l->c == NULL)
		{
			ft_putendl("Invalid spotlight");
			exit(-1);
		}
		l = l->next;
	}
}

void	check_spheres(void)
{
	t_sphere	*s;

	s = get_scene()->spheres;
	while (s != NULL)
	{
		if (s->center == NULL || s->color == NULL)
		{
			ft_putendl("Invalid sphere");
			exit(-1);
		}
		s = s->next;
	}
}

void	check_planes(void)
{
	t_plane		*p;

	p = get_scene()->planes;
	while (p != NULL)
	{
		if (p->normal == NULL || p->color == NULL)
		{
			ft_putendl("Invalid plane");
			exit(-1);
		}
		p = p->next;
	}
}

void	check_cones(void)
{
	t_cone		*c;

	c = get_scene()->cones;
	while (c != NULL)
	{
		if (c->center == NULL || c->axis == NULL || c->color == NULL ||
				c->upper == NULL || c->lower == NULL)
		{
			ft_putendl("Invalid cone");
			exit(-1);
		}
		c = c->next;
	}
}
