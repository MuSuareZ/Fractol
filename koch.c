/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:51:05 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/17 16:09:35 by msuarez-         ###   ########.fr       */
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
	z.newre = fabs(z.oldre * z.oldre - z.oldim * z.oldim + p.re);
	z.newim = fabs(2 * z.oldre * z.oldim + p.im);
	return (z);
}

static	t_mandel	p_calc(t_env *env, t_mandel p, int xy[2])
{
	p.re = 2.5 * (xy[0] - WIDTH / 2) / (0.5 * env->zoom * WIDTH) + env->pos.x;
	p.im = 2.5 * (xy[1] - HEIGHT / 2) / (0.5 * env->zoom * HEIGHT) + env->pos.y;
	return (p);
}

void				burning_ship(t_env *env, int iter)
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
			colors(env, xy, i, iter);
		}
	}
}
