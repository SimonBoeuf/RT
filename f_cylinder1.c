/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cylinder1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 19:18:00 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/26 21:44:13 by wtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

t_vect		*get_normal_at_cylinder(t_cylinder *c, t_vect *point)
{
	t_vect	*v;
	t_vect	*tmp1;
	t_vect	*tmp2;

	tmp1 = vect_sub(c->center, point);
	tmp2 = vect_project(tmp1, c->axis);
	v = vect_sub(tmp2, tmp1);
	v = normalize(v);
	delete_vect(tmp1);
	delete_vect(tmp2);
	return (v);
}

t_inter		*find_cylinders_intersection(t_ray *ray)
{
	double		mininter;
	double		inter;
	t_vect		*normal;
	t_color		*color;
	t_cylinder	*c;

	mininter = -1;
	c = get_scene()->cylinders;
	while (c != NULL)
	{
		inter = find_cylinder_intersection(c, ray);
		if (inter > ACCURACY && (inter < mininter || mininter == -1))
		{
			mininter = inter;
			normal = get_normal_at_cylinder(c, vect_add(ray->origin,
									vect_mult(ray->direction, inter)));
			color = c->color;
		}
		c = c->next;
	}
	return (new_inter(normal, mininter, color));
}

double		find_cylinder_intersection(t_cylinder *cy, t_ray *r)
{
	t_vect		*abc;
	double		d;
	double		rslt;

	abc = coeff_cylinder(cy, r);
	d = pow(abc->y, 2) - abc->x * abc->z;
	if (d > 0)
	{
		rslt = ((-abc->y - sqrt(d)) / abc->x) - 0.000001 > 0 ?
			(-abc->y - sqrt(d)) / abc->x - 0.000001 :
			(-abc->y + sqrt(d)) / abc->x - 0.000001;
	}
	else
		rslt = -1;
	delete_vect(abc);
	return (rslt);
}

t_cylinder	*get_cylinders(int fd)
{
	int			r;
	char		*line;
	t_cylinder	*c;

	c = NULL;
	while ((r = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "----------"))
	{
		if (!ft_strcmp("new:", line))
		{
			if (c == NULL)
				c = get_cylinder(fd);
			else
				add_cylinder(c, get_cylinder(fd));
		}
	}
	if (r == -1)
		exit(-1);
	return (c);
}

t_cylinder	*get_cylinder(int fd)
{
	int			r;
	char		*line;
	t_vect		*center;
	t_vect		*axis;
	double		radius;
	t_color		*color;

	while ((r = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "----------"))
	{
		if (!ft_strcmp("pos:", line))
			center = get_vector(fd);
		if (!ft_strcmp("radius:", line))
		{
			r = get_next_line(fd, &line);
			radius = ft_atodouble(&line);
		}
		if (!ft_strcmp("color:", line))
			color = get_color(fd);
		if (!ft_strcmp("axis:", line))
		{
			axis = get_vector(fd);
			axis = normalize(axis);
		}
	}
	if (r == -1)
		exit(-1);
		return (new_cylinder(center, radius, color, axis));
}
