/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sphere_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:08:02 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/27 19:29:55 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

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
		exit(-1);
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
