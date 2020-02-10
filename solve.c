/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:01:45 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/10 18:32:16 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


// void			init_img(t_env *env)
// {
// 	env->image = mlx_new_image(env->mlx, WIDTH, HEIGHT);
// 	env->buffer = (int *)mlx_get_data_addr(env->image, &env->pixel_bits,
// 									&env->line_bytes, &env->endian);
// 	env->line_bytes /= 4;
// 	env->color = 11111111;
// }

// void			make_me_black_senpai(t_env *env)
// {
// 	int	x;
// 	int	y;
	
// 	y = 0;
// 	while (y++ < HEIGHT - 1000)
// 	{
// 		x = 0;
// 		while (x++ < WIDTH)
//     		env->buffer[(y * env->line_bytes) + x] = env->color;
// 	}
// 	mlx_put_image_to_window(env->mlx, env->win, env->image, 0, 0);
// }

void			pixel_put(t_env *env, int x, int y, int color)
{
	mlx_pixel_put(env->mlx, env->win, x, y, color);
}
