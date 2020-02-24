/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:22:39 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/24 16:48:55 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_mandel		reset_z(t_mandel z)
{
	z.newim = 0;
	z.newre = 0;
	z.oldim = 0;
	z.oldre = 0;
	return (z);
}

static t_mandel		calc(t_mandel z, t_mandel p)
{
	z.oldre = z.newre;
	z.oldim = z.newim;
	z.newre = z.oldre * z.oldre - z.oldim * z.oldim + p.re;
	z.newim = 2 * z.oldre * z.oldim + p.im;
	return (z);
}

static	t_mandel	p_calc(t_env *env, t_mandel p, int xy[2])
{
	p.re = 2.5 * (xy[0] - WIDTH / 2) / (0.5 * env->zoom * WIDTH) + env->pos.x;
	p.im = 2.5 * (xy[1] - HEIGHT / 2) / (0.5 * env->zoom * HEIGHT) + env->pos.y;
	return (p);
}

void				mandelbrot_set(t_env *env, int iter)
{
	int					i;
	int					xy[2];
	t_mandel			p;
	t_mandel			z;

	xy[1] = 0;
	while (xy[1]++ < HEIGHT)
	{
		xy[0] = 0;
		while (xy[0]++ < WIDTH)
		{
			p = p_calc(env, p, xy);
			z = reset_z(z);
			i = 0;
			while (i++ < iter)
			{
				z = calc(z, p);
				if ((z.newre * z.newre + z.newim * z.newim) > 4)
					break ;
			}
			img_pixel_put(env, xy[0], xy[1], select_color(env, i));
		}
	}
}
