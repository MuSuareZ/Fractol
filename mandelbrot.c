/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:22:39 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/10 18:51:56 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_complex		first_z0value(t_complex z0)
{
	z0.x = 0.0;
	z0.y = 0.0;
	return (z0);
}

static t_complex		first_z1value(t_complex z0, t_complex z1)
{
	z1.x = z0.x * z0.x;
	z1.y = z0.y * z0.y;
	return (z1);
}

static t_complex		last_z0value(t_complex z0, t_complex z1, t_complex c)
{
	z0.y = 2 * z0.x * z0.y + c.y;
	z0.x = z1.x - z1.y + c.x;
	return (z0);
}

void	colors(t_env *env, int xy[2], int i, int iter)
{
	if (i > iter)
		pixel_put(env, xy[0], xy[1], 0xff6600);
	// else if (i > iter * 0.6)
	// 	pixel_put(env, xy[0], xy[1], 0xff6600);
	// else if (i > iter * 0.5)
	// 	pixel_put(env, xy[0], xy[1], 0xffff00);
	// else if (i > iter * 0.4)
	// 	pixel_put(env, xy[0], xy[1], 0xffff33);
	// else if (i > iter * 0.3)
	// 	pixel_put(env, xy[0], xy[1], 0xffff80);
	// else if (i > iter * 0.2)
	// 	pixel_put(env, xy[0], xy[1], 0xffffb3);
	// else
	// 	pixel_put(env, xy[0], xy[1], 0x3399ff);
}

void			mandelbrot_set(t_env *env, int iter)
{
	int			i;
	int			xy[2];
	t_complex	c;
	t_complex	z0;
	t_complex	z1;

	xy[1] = 0;
	while (xy[1]++ < HEIGHT)
	{
		c.y = (env->c_min.y + xy[1] * env->pixel_height) * env->zoom;
		if (fabs(c.y) < env->pixel_height / 2)
			c.y = 0.0;
		xy[0] = 0;
		while (xy[0]++ < WIDTH)
		{
			c.x = (env->c_min.x + xy[0] * env->pixel_width) * env->zoom;
			z0 = first_z0value(z0);
			z1 = first_z1value(z0, z1);
			i = 0;
			while (i++ < iter && ((z1.x + z1.y) < env->esc_radius_squared))
			{
				z0 = last_z0value(z0, z1, c);
				z1 = first_z1value(z0, z1);
			}
			colors(env, xy, i, iter);
		}
	}
}
