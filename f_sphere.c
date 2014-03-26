/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sphere.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 19:18:10 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/26 18:01:18 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

t_vect		*get_normal_at_sphere(t_sphere *sphere, t_vect *point)
{
	t_vect	*v;

	v = normalize(vect_add(point, negative(sphere->center)));
	return (v);
}

t_color		*get_sphere_color(t_sphere *s, t_ray *r, double inter)
{
	t_vect	*vn;
	t_vect	*ve;
	t_vect	*vp;
	double	phi;
	double	theta;
	double	u;
	double	v;

	(void)r;
	if (s->img == NULL)
		return (s->color);
	else
	{
		vn = new_vector(0, 1, 0);
		ve = new_vector(0, 0, 1);
		vp = normalize(vect_add(r->origin, vect_mult(r->direction, inter)));
		phi = acos(-dot_product(vn, vp));
		v = phi / (M_PI);
		theta = acos(dot_product(vp, ve) / sin(phi)) / (2 * M_PI);
		if (dot_product(crossProduct(vn, ve), vp) > 0)
			u = theta;
		else
			u = 1 - theta;
	}
	return (get_uv_color(s->img, u, v));
}

t_inter		*find_spheres_intersection(t_ray *ray)
{
	double		mininter;
	double		inter;
	t_vect		*normal;
	t_color		*c;
	t_sphere	*s;

	mininter = -1;
	s = get_scene()->spheres;
	while (s != NULL)
	{
		inter = find_sphere_intersection(s, ray);
		if (inter > ACCURACY && (inter < mininter || mininter == -1))
		{
			mininter = inter;
			normal = get_normal_at_sphere(s, vect_add(ray->origin,
									vect_mult(ray->direction, inter)));
			c = get_sphere_color(s, ray, inter);
		}
		s = s->next;
	}
	return (new_inter(normal, mininter, c));
}

double		find_sphere_intersection(t_sphere *s, t_ray *r)
{
	double	b;
	double	c;
	double	d;
	double	rslt;

	b = (2 * (r->origin->x - s->center->x) * r->direction->x) +
		(2 * (r->origin->y - s->center->y) * r->direction->y) +
		(2 * (r->origin->z - s->center->z) * r->direction->z);
	c = pow(r->origin->x - s->center->x, 2) +
		pow(r->origin->y - s->center->y, 2) +
		pow(r->origin->z - s->center->z, 2) - (s->radius * s->radius);
	d = b * b - 4 * c;
	if (d > 0)
	{
		rslt = ((-b - sqrt(d)) / 2) - 0.000001 > 0 ?
			(-b - sqrt(d)) / 2 - 0.000001 :
			(-b + sqrt(d)) / 2 - 0.000001;
	}
	else
		rslt = -1;
	return (rslt);
}

t_sphere	*get_spheres(int fd)
{
	int			r;
	char		*line;
	t_sphere	*s;

	s = NULL;
	while ((r = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "----------"))
	{
		if (!ft_strcmp("new:", line))
		{
			if (s == NULL)
				s = get_sphere(fd);
			else
				add_sphere(s, get_sphere(fd));
		}
	}
	if (r == -1)
		exit (-1);
	return (s);
}

t_sphere	*get_sphere(int fd)
{
	int			r;
	char		*line;
	t_sphere	*s;

	s = new_sphere(NULL, 0, NULL, NULL);
	while ((r = get_next_line(fd, &line)) > 0 && ft_strcmp(line, "----------"))
	{
		if (!ft_strcmp("pos:", line))
			s->center = get_vector(fd);
		if (!ft_strcmp("radius:", line))
		{
			r = get_next_line(fd, &line);
			s->radius = ft_atodouble(&line);
		}
		if (!ft_strcmp("color:", line))
			s->color = get_color(fd);
		if (!ft_strcmp("img:", line))
		{
			r = get_next_line(fd, &line);
			s->img = init_img_from_file(line);
		}
	}
	if (r == -1)
			exit(-1);
	return (s);
}
