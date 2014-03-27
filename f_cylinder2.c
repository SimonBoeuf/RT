/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cylinder2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtrembla <wtrembla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 20:49:21 by wtrembla          #+#    #+#             */
/*   Updated: 2014/03/27 19:06:45 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

static t_vect	*define_x_vect(t_cylinder *cylinder, t_ray *ray)
{
	t_vect	*tmp1;
	t_vect	*tmp2;

	tmp1 = vect_mult(cylinder->axis, dot_product(ray->direction,
												cylinder->axis));
	tmp2 = vect_sub(tmp1, ray->direction);
	delete_vect(tmp1);
	return (tmp2);
}

static t_vect	*define_y_vect(t_cylinder *cylinder, t_ray *ray)
{
	t_vect	*tmp1;
	t_vect	*tmp2;
	t_vect	*tmp3;

	tmp1 = vect_sub(cylinder->center, ray->origin);
	tmp2 = vect_mult(cylinder->axis, dot_product(tmp1, cylinder->axis));
	tmp3 = vect_sub(tmp2, tmp1);
	delete_vect(tmp1);
	delete_vect(tmp2);
	return (tmp3);
}

t_vect			*coeff_cylinder(t_cylinder *cylinder, t_ray *ray)
{
	t_vect	*abc;
	t_vect	*x;
	t_vect	*y;

	x = define_x_vect(cylinder, ray);
	y = define_y_vect(cylinder, ray);
	abc = new_vector(dot_product(x, x), dot_product(x, y),
					dot_product(y, y) - pow(cylinder->radius, 2));
	delete_vect(x);
	delete_vect(y);
	return (abc);
}

int				check_finite_cyl(t_cylinder *cy, t_vect *point)
{
	t_vect		*sub1;
	t_vect		*sub2;

	sub1 = vect_sub(cy->center, point);
	sub2 = vect_sub(cy->upper, point);
	if (dot_product(sub1, cy->axis) > 0 && dot_product(sub2, cy->axis) < 0)
	{
		delete_vect(sub1);
		delete_vect(sub2);
		return (1);
	}
	delete_vect(sub1);
	delete_vect(sub2);
	return (0);
}
