/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:27:35 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/04 18:23:09 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_complex	ft_add(t_complex a, t_complex b)
{
	t_complex c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_complex	ft_sqr(t_complex a)
{
	t_complex c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}

double		ft_mod(t_complex a)
{
	return (sqrt(a.x * a.x + a.y * a.y));
}

t_complex	map_point(double radius, int x, int y)
{
	t_complex	c;
	int			len;

	len = (WIDTH < HEIGHT) ? WIDTH : HEIGHT;
	c.x = 2 * radius * (x - WIDTH / 2.0) / len;
	c.y = 2 * radius * (y - HEIGHT / 2.0) / len;
	return (c);
}

void	julia_set(t_complex c, double radius, int n, t_env *env)
{
	int				x;
	int				y;
	int				i;
	t_complex		z0;
	t_complex		z1;

	x = 0;
	while (x++ <= WIDTH)
	{
		y = 0;
		while (y++ <= HEIGHT)
		{
			z0 = map_point(radius, x, y);
			i = 1;
			while (i++ <= n)
			{
				z1 = ft_add(ft_sqr(z0), c);
				if (ft_mod(z1) > radius)
				{
					pixel_put(env, x, y, 0x000000);
					break ;
				}
				z0 = z1;
			}
			if (i > n)
				pixel_put(env, x, y, 0xff33cc);
		}
	}
}
