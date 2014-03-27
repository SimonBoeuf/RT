/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cone1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtrembla <wtrembla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 21:48:06 by wtrembla          #+#    #+#             */
/*   Updated: 2014/03/27 19:32:44 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

t_vect		*get_normal_at_cone(t_cone *c, t_vect *point)
{
	t_vect		*v;
	t_vect		*tmp1;
	t_vect		*tmp2;
	t_vect		*tmp3;
	t_vect		*tmp4;

	tmp1 = vect_sub(c->center, point);
	tmp2 = vect_project(tmp1, c->axis);
	tmp3 = vect_sub(tmp2, tmp1);
	if (dot_product(tmp1, c->axis) < 0)
		tmp4 = cross_product(tmp3, c->axis);
	else
		tmp4 = cross_product(c->axis, tmp3);
	v = cross_product(tmp4, tmp1);
	v = normalize(v);
	delete_vect(tmp1);
	delete_vect(tmp2);
	delete_vect(tmp3);
	delete_vect(tmp4);
	return (v);
}

t_inter		*find_cones_intersection(t_ray *ray)
{
	double		mininter;
	double		inter;
	t_vect		*normal;
	t_color		*color;
	t_cone		*c;

	mininter = -1;
	c = get_scene()->cones;
	while (c != NULL)
	{
		inter = find_cone_intersection(c, ray);
		if (inter > ACCURACY && (inter < mininter || mininter == -1))
		{
			mininter = inter;
			normal = get_normal_at_cone(c, vect_add(ray->origin,
										vect_mult(ray->direction, inter)));
			color = c->color;
		}
		c = c->next;
	}
	return (new_inter(normal, mininter, color));
}

double		find_cone_intersection(t_cone *c, t_ray *r)
{
	t_vect		*abc;
	double		d;
	double		rslt;
	t_vect		*point;

	abc = coeff_cone(c, r);
	d = pow(abc->y, 2) - abc->x * abc->z;
	if (d > 0)
	{
		rslt = ((-abc->y - sqrt(d)) / abc->x) - 0.000001 > 0 ?
			(-abc->y - sqrt(d)) / abc->x - 0.000001 :
			(-abc->y + sqrt(d)) / abc->x - 0.000001;
		point = vect_add(r->origin, vect_mult(r->direction, rslt));
		if (!check_finite_co(c, point))
			rslt = -1;
	}
	else
		rslt = -1;
	delete_vect(abc);
	return (rslt);
}

t_cone		*get_cones(int fd)
{
	int			r;
	char		*line;
	t_cone		*c;

	c = NULL;
	while ((r = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "----------"))
	{
		if (!ft_strcmp("new:", line))
		{
			if (c == NULL)
				c = get_cone(fd);
			else
				add_cone(c, get_cone(fd));
		}
	}
	if (r == -1)
		exit(-1);
	return (c);
}

t_cone		*get_cone(int fd)
{
	int			r;
	char		*line;
	t_cone		*c;

	c = new_cone(NULL, 0, NULL, NULL);
	while ((r = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "----------"))
	{
		if (!ft_strcmp("pos:", line))
			c->center = get_vector(fd);
		if (!ft_strcmp("upper:", line))
			c->upper = get_vector(fd);
		if (!ft_strcmp("lower:", line))
			c->lower = get_vector(fd);
		if (!ft_strcmp("angle:", line))
		{
			r = get_next_line(fd, &line);
			c->alpha = ft_atodouble(&line) * M_PI / 180;
		}
		if (!ft_strcmp("color:", line))
			c->color = get_color(fd);
		if (!ft_strcmp("axis:", line))
			c->axis = normalize(get_vector(fd));
	}
	calc_trigo(c);
	return (c);
}
