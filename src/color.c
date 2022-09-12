/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:33:44 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/24 17:12:43 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int		return_wiki_colors(int n)
{
	int		colors[16];

	colors[0] = 0x421E0F;
	colors[1] = 0x19071A;
	colors[2] = 0x09012F;
	colors[3] = 0x040449;
	colors[4] = 0x000764;
	colors[5] = 0x0C2C8A;
	colors[6] = 0x1852B1;
	colors[7] = 0x397DD1;
	colors[8] = 0x86B5D1;
	colors[9] = 0xD3ECF8;
	colors[10] = 0xF1E9BF;
	colors[11] = 0xF8C95F;
	colors[12] = 0xFFAA00;
	colors[13] = 0xCC8000;
	colors[14] = 0x995700;
	colors[15] = 0x6A3403;
	return (colors[n]);
}

static	int		get_wiki_color(int i, t_env *env)
{
	int		n;

	if (i == env->iter || i < 0)
		return (0x000000);
	n = i % 16;
	return (return_wiki_colors(n));
}

static	int		get_rainbow_color(int i, t_env *env)
{
	float	frequency;
	t_rgb	color;

	frequency = .1;
	if (i == env->iter)
		return (0x000000);
	color.red = sin(frequency * i + 0) * 127 + 128;
	color.green = sin(frequency * i + 2) * 127 + 128;
	color.blue = sin(frequency * i + 4) * 127 + 128;
	return ((color.red << 16) + (color.green << 8) + color.blue);
}

static	int		get_greyscale_color(int i, t_env *env)
{
	int		n;
	int		s;

	s = env->iter;
	if (i == env->iter)
		return (0x000000);
	n = i;
	return (((n * 255 / s) << 16) + ((n * 255 / s) << 8) + n * 255 / s);
}

int				select_color(t_env *env, int i)
{
	if (env->color_num == 1)
		return (get_wiki_color(i, env));
	else if (env->color_num == 2)
		return (get_rainbow_color(i, env));
	else if (env->color_num == 3)
		return (get_greyscale_color(i, env));
	return (0xffffff);
}
