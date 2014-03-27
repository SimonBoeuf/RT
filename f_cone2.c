/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cone2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtrembla <wtrembla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 21:56:59 by wtrembla          #+#    #+#             */
/*   Updated: 2014/03/27 18:23:06 by wtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

static t_vect		*define_x_vect(t_cone *cone, t_ray *ray)
{
	t_vect	*tmp1;
	t_vect	*tmp2;

	tmp1 = vect_mult(cone->axis, dot_product(ray->direction, cone->axis));
	tmp2 = vect_sub(tmp1, ray->direction);
	delete_vect(tmp1);
	return (tmp2);
}

static t_vect		*define_y_vect(t_cone *cone, t_ray *ray)
{
	t_vect	*tmp1;
	t_vect	*tmp2;
	t_vect	*tmp3;

	tmp1 = vect_sub(cone->center, ray->origin);
	tmp2 = vect_mult(cone->axis, dot_product(tmp1, cone->axis));
	tmp3 = vect_sub(tmp2, tmp1);
	delete_vect(tmp1);
	delete_vect(tmp2);
	return (tmp3);
}

static double		define_dot2(t_cone *cone, t_ray *ray)
{
	double	dot2;
	t_vect	*tmp;

	tmp = vect_sub(cone->center, ray->origin);
	dot2 = dot_product(cone->axis, tmp);
	delete_vect(tmp);
	return (dot2);
}

t_vect				*coeff_cone(t_cone *cone, t_ray *ray)
{
	double	dot1;
	double	dot2;
	t_vect	*abc;
	t_vect	*x;
	t_vect	*y;
	dot1 = dot_product(ray->direction, cone->axis);
	dot2 = define_dot2(cone, ray);
	x = define_x_vect(cone, ray);
	y = define_y_vect(cone, ray);
	abc = new_vector(cone->cos2 * dot_product(x, x) - cone->sin2 * pow(dot1, 2),
					 cone->cos2 * dot_product(x, y) - cone->sin2 * dot1 * dot2,
					 cone->cos2 * dot_product(y, y) - cone->sin2 * pow(dot2, 2));
	return (abc);
}

int					check_finite_co(t_cone *co, t_vect *point)
{
	t_vect 		*sub1;
	t_vect		*sub2;

	sub1 = vect_sub(co->lower, point);
	sub2 = vect_sub(co->upper, point);
	if (dot_product(sub1, co->axis) > 0 && dot_product(sub2, co->axis) < 0)
	{
		delete_vect(sub1);
		delete_vect(sub2);
		return (1);
	}
	delete_vect(sub1);
	delete_vect(sub2);
	return(0);
}
