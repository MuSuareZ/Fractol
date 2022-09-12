/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:58:47 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/26 18:00:21 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
**	idx() - Useful function to get the row, col value from a flattened
**	2D matrix. Dim is the 'width' of the matrix...
*/

static int		idx(int row, int col, int dim)
{
	return (row * dim + col);
}

void			init_img(t_env *env)
{
	t_image	*img;

	img = &env->img;
	img->image = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->line_s,
								&img->endian);
	img->bpp /= 8;
}

void			img_pixel_put(t_env *env, double x, double y, int color)
{
	t_image *img;

	img = &(env->img);
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int *)(img->ptr + (int)(idx(y, x, WIDTH) * img->bpp)) = color;
}

void			clear_img(t_env *env)
{
	t_image *img;

	img = &(env->img);
	ft_bzero(img->ptr, (WIDTH * HEIGHT) * img->bpp);
}
