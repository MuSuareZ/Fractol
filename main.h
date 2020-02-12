/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:55:24 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/12 17:33:17 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"

# define ESC 53
# define WIDTH 1000
# define HEIGHT 1000
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define UP 126
# define DOWN 125
# define D 2
# define A 0
# define W 13
# define S 1
# define K 40
# define L 37
# define WHITE 0xFFFFFF

typedef struct	s_complex
{
	double x;
	double y;
}				t_complex;

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	int		iter;
	int		proj_num;
	int		julia_var;
	t_complex		julia;
	t_complex		pos;
	t_coord		p1;
	t_coord		p2;
	double		pixel_width;
	double		pixel_height;
	long double		zoom;
}					t_env;

int		event_mouse(int button, int x, int y, t_env *e);
int		event_key(int keycode, t_env *e);
int		mouse_move(int x, int y, t_env *e);
void	pixel_put(t_env *env, int x, int y, int color);
void	koch_curve(t_env *env, t_coord p1, t_coord p2, int times);
void	julia_set(t_complex c, double radius, int n, t_env *env);
void	mandelbrot_set(t_env *env, int iter);
void	draw_again(t_env *e);
void	colors(t_env *env, int xy[2], int i, int iter);

#endif
