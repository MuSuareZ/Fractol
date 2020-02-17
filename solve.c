/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:01:45 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/17 17:49:30 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// void			init_img(t_env *env)
// {
// 	int     bpp;
// 	int		size_line;
// 	int     endian;

// 	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
// 	env->img_data = (int *)mlx_get_data_addr(env->img, &bpp, &size_line, &endian);
// 	// env->size_line = WIDTH / 4;
// 	env->endian = endian;
// }

void			draw_again(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	// init_img(e);
	mlx_string_put(e->mlx, e->win, 10, 5, 0xFFFFFF, \
						ft_strjoin("Number of iterations : ", \
						ft_itoa(e->iter)));
	mlx_string_put(e->mlx, e->win, 10, 35, 0xFFFFFF, \
						ft_strjoin("Zoom level: x", \
						ft_itoa(e->zoom)));
	mlx_string_put(e->mlx, e->win, 10, 65, 0xFFFFFF, \
						ft_strjoin("Julia Var: ", \
						ft_itoa(e->julia_var)));
	mlx_string_put(e->mlx, e->win, 10, 95, 0xFFFFFF, \
						ft_strjoin("Mouse X: ", \
						ft_itoa(e->mouse.x)));
	mlx_string_put(e->mlx, e->win, 10, 125, 0xFFFFFF, \
						ft_strjoin("Mouse Y: ", \
						ft_itoa(e->mouse.y)));
	if (e->proj_num == 1)
		burning_ship(e, e->iter);
	else if (e->proj_num == 2)
		julia_set(e->julia, e->iter, e);
	else
		mandelbrot_set(e, e->iter);
	// mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void			colors(t_env *env, int xy[2], int i, int iter)
{
	// if (i > iter)
	// 	pix_to_img(env, xy, 0xff6600);
	// else if (i > iter * 0.6)
	// 	pix_to_img(env, xy, 0xff6600);
	// else if (i > iter * 0.5)
	// 	pix_to_img(env, xy, 0xffff00);
	// else if (i > iter * 0.4)
	// 	pix_to_img(env, xy, 0xffff33);
	// else if (i > iter * 0.3)
	// 	pix_to_img(env, xy, 0xffff80);
	// else if (i > iter * 0.2)
	// 	pix_to_img(env, xy, 0xffffb3);
	if (i > iter)
		pixel_put(env, xy[0], xy[1], 0xff6600);
	else if (i > iter * 0.6)
		pixel_put(env, xy[0], xy[1], 0x000066);
	else if (i > iter * 0.5)
		pixel_put(env, xy[0], xy[1], 0xffff00);
	else if (i > iter * 0.4)
		pixel_put(env, xy[0], xy[1], 0xffff33);
	else if (i > iter * 0.3)
		pixel_put(env, xy[0], xy[1], 0xffff80);
	else if (i > iter * 0.2)
		pixel_put(env, xy[0], xy[1], 0xffffb3);
}

void			pix_to_img(t_env *env, int xy[2], int color)
{
	int		pixel;

	pixel = (xy[1] * WIDTH + xy[0]);
	if (env->endian == 1)        // Most significant (Alpha) byte first
    {
        env->img_data[pixel + 0] = color;
    	env->img_data[pixel + 1] = color;
    	env->img_data[pixel + 2] = color;
    	env->img_data[pixel + 3] = color;
    }
	else if (env->endian == 0)   // Least significant (Blue) byte first
    {
    	env->img_data[pixel + 0] = color;
    	env->img_data[pixel + 1] = color;
    	env->img_data[pixel + 2] = color;
    	env->img_data[pixel + 3] = color;
    }
}

void			pixel_put(t_env *env, int x, int y, int color)
{
	mlx_pixel_put(env->mlx, env->win, x, y, color);
}
