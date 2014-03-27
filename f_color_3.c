/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_color_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:00:06 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/27 19:42:04 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rtv1.h"

t_color	*get_color_from_number(int red, int green, int blue)
{
	float	new_red;
	float	new_green;
	float	new_blue;
	t_color	*c;

	new_red = (float)red / 255;
	new_green = (float)green / 255;
	new_blue = (float)blue / 255;
	c = new_color(new_red, new_green, new_blue, 3.9);
	return (c);
}
