/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 19:21:07 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/27 19:25:19 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

void	display_scene(void)
{
	t_win	*window;

	window = init_env();
	window->img = init_img();
	mlx_put_image_to_window(window->mlx, window->win, window->img->img, 0, 0);
	ft_draw_img();
	mlx_hook(window->win, 2, (1L << 0), ft_key_hook, window);
	mlx_expose_hook(window->win, ft_expose_hook, window);
	mlx_loop(window->mlx);
}

void	rtv1(char *scene_file)
{
	init_scene(scene_file);
	check_scene();
	display_scene();
}

void	init_scene(char *scene_file)
{
	int		fd;
	int		ret;
	char	*line;
	t_scene	*s;

	if ((fd = open(scene_file, O_RDONLY)) == -1)
		exit(-1);
	s = get_scene();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!ft_strcmp("camera:", line))
			s->cam = get_camera(fd);
		if (!ft_strcmp("spheres:", line))
			s->spheres = get_spheres(fd);
		if (!ft_strcmp("planes:", line))
			s->planes = get_planes(fd);
		if (!ft_strcmp("spots:", line))
			s->lights = get_spots(fd);
		if (!ft_strcmp("cylinders:", line))
			s->cylinders = get_cylinders(fd);
		if (!ft_strcmp("cones:", line))
			s->cones = get_cones(fd);
	}
	if (ret == -1)
		exit(-1);
}

void	check_scene(void)
{
	check_camera();
	check_lights();
	check_cylinders();
	check_cones();
	check_spheres();
	check_planes();
}
