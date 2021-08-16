/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:16:38 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/16 10:51:14 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/libft/libft.h"
# ifdef __linux
#  include "../lib/minilibx-linux/mlx.h"
#  include "../lib/minilibx-linux/mlx_int.h"
# else
#  include "../lib/minilibx_opengl/mlx.h"
# endif
# include "lmkeycodes.h"
# include <math.h>
# include <stdio.h>

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_render
{
	int			w;
	int			h;
	double		posx;
	double		posy;
	double		zoom;
	t_complex	c;
	int			iter;
	int			color;
	int			type;
	int			exit;
	t_data		img;
	t_vars		vars;
}				t_render;

/*
**  mlx especial functions
*/

void	mlx_pixel_put_ex(t_data *data, int x, int y, int color);
void	new_image(t_data *img, t_vars *vars, int width, int height);
int		create_trgb(int t, int r, int g, int b);
int		create_color(int i);

/*
**  fract-ol functions
*/

int		main_key_hook(int keycode, t_render *render);
int		mouse_hook(int button, int x, int y, t_render *render);
int		render_next_frame(void *render);
void	free_all(t_render *render);
void	julia(t_render *tr, int x, int y);
void	mandelbrot(t_render *tr, int x, int y);

#endif
