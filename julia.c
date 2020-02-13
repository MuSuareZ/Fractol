/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:27:35 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/13 14:59:37 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_complex	ft_add(t_complex a, t_complex b)
{
	t_complex c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

static t_complex	ft_sqr(t_complex a)
{
	t_complex c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}

static double		ft_mod(t_complex a)
{
	return (sqrt(a.x * a.x + a.y * a.y));
}

static t_complex	map_point(double radius, int x, int y, t_env *env)
{
	t_complex	c;
	int			len;

	len = (WIDTH < HEIGHT) ? WIDTH : HEIGHT;
	c.x = 2 * radius * (env->pos.x + x - WIDTH / 2.0) / len * env->zoom;
	c.y = 2 * radius * (env->pos.y + y - HEIGHT / 2.0) / len * env->zoom;
	return (c);
}

void				julia_set(t_complex c, double radius, int n, t_env *env)
{
	int				xy[2];
	int				i;
	t_complex		z0;
	t_complex		z1;

	xy[0] = 0;
	while (xy[0]++ <= WIDTH)
	{
		xy[1] = 0;
		while (xy[1]++ <= HEIGHT)
		{
			z0 = map_point(radius, xy[0], xy[1], env);
			i = 1;
			while (i++ <= n)
			{
				z1 = ft_add(ft_sqr(z0), c);
				if (ft_mod(z1) > radius)
					break ;
				z0 = z1;
			}
			colors(env, xy, i, n);
		}
	}
}
