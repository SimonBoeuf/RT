/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_vect2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtrembla <wtrembla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 19:51:55 by wtrembla          #+#    #+#             */
/*   Updated: 2014/03/26 21:10:39 by wtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

t_vect		*vect_sub(t_vect *v1, t_vect *v2)
{
	t_vect	*rslt;

	rslt = new_vector(v2->x - v1->x, v2->y - v1->y, v2->z - v1->z);
	return (rslt);
}

t_vect		*vect_project(t_vect *v1, t_vect *v2)
{
	double		dot1;
	double		dot2;
	t_vect		*project;

	dot1 = dot_product(v1, v2);
	dot2 = dot_product(v2, v2);
	project = new_vector(v2->x * dot1 / dot2, v2->y * dot1 / dot2,
						 v2->z * dot1 / dot2);
	return (project);
}
