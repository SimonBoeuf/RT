/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 19:18:58 by sboeuf            #+#    #+#             */
/*   Updated: 2014/03/27 19:09:27 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rtv1.h"

t_img			*init_img(void)
{
	t_win	*win;
	t_img	*img;

	win = init_env();
	img = (t_img*)malloc(sizeof(t_img));
	img->img = mlx_new_image(win->mlx, WD, HI);
	img->hi = HI;
	img->wd = WD;
	img->data = mlx_get_data_addr(img->img, &img->bbp,
									&img->size_line, &img->endian);
	return (img);
}

t_img			*init_img_from_file(char *filename)
{
	t_win	*win;
	t_img	*img;
	int		hi;
	int		wd;

	win = init_env();
	img = (t_img*)malloc(sizeof(t_img));
	img->img = mlx_xpm_file_to_image(win->mlx, filename, &wd, &hi);
	img->hi = hi;
	img->wd = wd;
	img->data = mlx_get_data_addr(img->img, &img->bbp,
									&img->size_line, &img->endian);
	win->img = init_img();
	return (img);
}

t_color			*get_uv_color(t_img *img, double u, double v)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	red = img->data[(img->hi - (int)(v * img->hi)) * img->size_line +
		(img->wd - (int)(u * img->wd)) * 4 + 2];
	green = img->data[(img->hi - (int)(v * img->hi)) * img->size_line +
		(img->wd - (int)(u * img->wd)) * 4 + 1];
	blue = img->data[(img->hi - (int)(v * img->hi)) * img->size_line +
		(img->wd - (int)(u * img->wd)) * 4];
	return (get_color_from_number(red, green, blue));
}

void			img_del(t_img *img)
{
	if (img)
	{
		if (img->img != NULL)
			free(img->img);
		free(img);
	}
}
