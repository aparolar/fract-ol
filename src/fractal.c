/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 12:30:02 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/14 17:55:05 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	julia(t_render *tr, int x, int y)
{
	t_complex	z;
	int			count;
	double		tx;

	z.real = 1.5 * (x - tr->w / 2);
	z.real = z.real / (0.4 * tr->zoom * tr->w);
	z.real += tr->posx;
	z.imag = (y - tr->h / 2);
	z.imag = z.imag / (0.4 * tr->zoom * tr->h);
	z.imag += tr->posy;
	count = 0;
	while ((z.real * z.real + z.imag * z.imag < 4.0f) && count < tr->iter)
	{
		tx = z.real * z.real - z.imag * z.imag + tr->c.real;
		z.imag = 2 * z.real * z.imag + tr->c.imag;
		z.real = tx;
		count++;
	}
	mlx_pixel_put_ex(&tr->img, x, y, create_color(count));
}

void	mandelbrot(t_render *tr, int x, int y)
{
	t_complex	z;
	int			count;
	float		tx;

	tr->posx = -0.3;
	tr->c.real = 1.5 * (x - tr->w / 2);
	tr->c.real = tr->c.real / (0.4 * tr->zoom * tr->w);
	tr->c.real += tr->posx + (tr->posx / tr->zoom);
	tr->c.imag = (y - tr->h / 2);
	tr->c.imag = tr->c.imag / (0.4 * tr->zoom * tr->h);
	tr->c.imag += tr->posy + (tr->posy / tr->zoom);
	z.real = 0;
	z.imag = 0;
	count = 0;
	while ((z.real * z.real + z.imag * z.imag < 4.0f) && count < tr->iter)
	{
		tx = z.real * z.real - z.imag * z.imag + tr->c.real;
		z.imag = 2 * z.real * z.imag + tr->c.imag;
		z.real = tx;
		count++;
	}
	mlx_pixel_put_ex(&tr->img, x, y, create_color(count));
}
