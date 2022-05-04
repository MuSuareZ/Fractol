/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:55:24 by msuarez-          #+#    #+#             */
/*   Updated: 2020/03/09 17:47:52 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define ESC 53
# define WIDTH 1000
# define HEIGHT 1000
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define GREYSCALE 20
# define RAINBOW 19
# define COLOR 18
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define W 13
# define S 1
# define K 40
# define R 15
# define THREADS 8

typedef struct	s_mandel
{
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	double	re;
	double	im;
}				t_mandel;

typedef struct	s_complex
{
	double x;
	double y;
}				t_complex;

typedef struct	s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			line_s;
	int			endian;
}				t_image;

typedef struct	s_pixel
{
	t_complex	c;
	long		i;
}				t_pixel;

typedef struct	s_rgb
{
	int				red;
	int				green;
	int				blue;
}				t_rgb;

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	int				iter;
	int				color_num;
	int				proj_num;
	int				julia_var;
	int				start;
	int				thread_id;
	t_image			img;
	t_pixel			*data;
	t_mandel		mandel;
	t_complex		julia;
	t_complex		pos;
	t_complex		mouse;
	long double		zoom;
}				t_env;

int				event_mouse(int button, int x, int y, t_env *e);
int				event_key(int keycode, t_env *e);
int				mouse_move(int x, int y, t_env *e);
void			*burning_ship(void *env_ptr);
void			*julia_set(void *env_ptr);
void			*mandelbrot_set(void *env_ptr);
void			draw_again(t_env *e);
void			img_pixel_put(t_env *env, double x, double y, int color);
void			draw_info(t_env *e);
void			init_img(t_env *env);
int				select_color(t_env *env, int i);
void			clear_img(t_env *env);

#endif
