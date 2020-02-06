/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:01:45 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/06 14:18:26 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			pixel_put(t_env *env, int x, int y, int color)
{
	mlx_pixel_put(env->mlx, env->win, env->pos.x + x, env->pos.y + y, color);
}
