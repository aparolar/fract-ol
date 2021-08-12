/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:55:05 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/12 14:48:33 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	key_move(int keycode, t_render *render)
{
	if (keycode == KEY_DOWN)
		render->posy -= 0.10f / render->zoom;
	else if (keycode == KEY_UP)
		render->posy += 0.10f / render->zoom;
	else if (keycode == KEY_LEFT)
		render->posx += 0.10f / render->zoom;
	else if (keycode == KEY_RIGHT)
		render->posx -= 0.10f / render->zoom;
}

static void	key_change_julia(int keycode, t_render *render)
{
	if (keycode == KEY_1)
		render->c.real -= 0.01;
	else if (keycode == KEY_2)
		render->c.real += 0.01;
	else if (keycode == KEY_3)
		render->c.imag += 0.02;
	else if (keycode == KEY_4)
		render->c.imag -= 0.02;
}

int	main_key_hook(int keycode, t_render *render)
{
	if (keycode == KEY_ESC)
	{
		free_all(render);
		exit(EXIT_SUCCESS);
	}
	key_move(keycode, render);
	key_change_julia(keycode, render);
	if (keycode == KEY_PLUS)
		render->zoom *= 1.25f;
	if (keycode == KEY_MINUS && render->zoom / 1.25f >= 1)
		render->zoom /= 1.25f;
	if (keycode == KEY_0 && render->iter + 10 < 500)
		render->iter += 10;
	if (keycode == KEY_9 && render->iter - 10 > 9)
		render->iter -= 10;
	render_next_frame(render);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_render *render)
{
	printf("mouse x = %d y = %d\n", x, y);
	if (button == 4)
		render->zoom *= 1.25f;
	else if (button == 5)
		render->zoom /= 1.25f;
	render_next_frame(render);
	return (0);
}

int	render_next_frame(void *render)
{
	t_render	*tr;
	int			x;
	int			y;

	tr = (t_render *)render;
	mlx_do_sync(tr->vars.mlx);
	y = 0;
	while (y < tr->h)
	{
		x = 0;
		while (x < tr->w)
		{
			if (tr->type == 1)
				julia(render, x, y);
			else
				mandelbrot(render, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(tr->vars.mlx, tr->vars.win, tr->img.img, 0, 0);
	return (0);
}
