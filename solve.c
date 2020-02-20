/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:01:45 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/20 18:03:12 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
**	idx() - Useful function to get the row, col value from a flattened
**	2D matrix. Dim is the 'width' of the matrix...
*/

void			draw_again(t_env *e)
{
	clear_img(e);
	if (e->proj_num == 1)
		burning_ship(e, e->iter);
	else if (e->proj_num == 2)
		julia_set(e->julia, e->iter, e);
	else
		mandelbrot_set(e, e->iter);
	mlx_put_image_to_window(e->mlx, e->win, e->img.image, 0, 0);
	draw_info(e);
}

void			draw_info(t_env *e)
{
	char	*tmp;

	tmp = ft_itoa(e->iter);
	mlx_string_put(e->mlx, e->win, 10, 22, 0x00FFFFFF, "Iterations :");
	mlx_string_put(e->mlx, e->win, 140, 22, 0x00FFFFFF, tmp);
	free(tmp);
	tmp = ft_itoa(e->julia_var);
	mlx_string_put(e->mlx, e->win, 10, 44, 0x00FFFFFF, "Julia Var  :");
	mlx_string_put(e->mlx, e->win, 140, 44, 0x00FFFFFF, tmp);
	free(tmp);
	tmp = ft_itoa(e->mouse.x);
	mlx_string_put(e->mlx, e->win, 10, 66, 0x00FFFFFF, "Mouse X    :");
	mlx_string_put(e->mlx, e->win, 140, 66, 0x00FFFFFF, tmp);
	free(tmp);
	tmp = ft_itoa(e->mouse.y);
	mlx_string_put(e->mlx, e->win, 10, 88, 0x00FFFFFF, "Mouse Y    :");
	mlx_string_put(e->mlx, e->win, 140, 88, 0x00FFFFFF, tmp);
	free(tmp);
}

void			colors(t_env *env, int xy[2], int i, int iter)
{
	if (i > iter)
		img_pixel_put(env, xy[0], xy[1], 0xff6600);
	else if (i > iter * 0.6)
		img_pixel_put(env, xy[0], xy[1], 0xff6600);
	else if (i > iter * 0.5)
		img_pixel_put(env, xy[0], xy[1], 0xffff00);
	else if (i > iter * 0.4)
		img_pixel_put(env, xy[0], xy[1], 0xffff33);
	else if (i > iter * 0.3)
		img_pixel_put(env, xy[0], xy[1], 0xffff80);
	else if (i > iter * 0.2)
		img_pixel_put(env, xy[0], xy[1], 0xffffb3);
}
