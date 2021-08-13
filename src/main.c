/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:59:21 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/13 16:54:23 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	print_options(void)
{
	ft_putstr("error: invalid option.\n");
	ft_putstr("Please, choise a correct option from de list.\n");
	ft_putstr("\t1 : Julia\n");
	ft_putstr("\t2 : Mandelbrot\n");
}

static int	check_params(int argc, char **argv)
{
	if (argc < 2)
	{	
		ft_putstr("error. invalid parameters\n");
		exit(0);
	}
	else
	{
		if (argv[1][0] != '1' && argv[1][0] != '2')
		{
			print_options();
			exit(0);
		}
		else
			return (ft_atoi(argv[1]));
	}
}

static void	pre_init_graphics(t_render *render)
{
	render->w = 1400;
	render->h = 800;
	render->posx = 0.0f;
	render->posy = 0.0f;
	render->iter = 300;
	render->zoom = 1.0f;
	render->c.real = -0.74f;
	render->c.imag = 0.27015f;
	render->color = 0;
	render->type = 0;
	render->vars.mlx = mlx_init();
	if (render->vars.mlx)
	{
		render->vars.win = mlx_new_window(
				render->vars.mlx,
				render->w,
				render->h,
				"Frac-oool!");
		new_image(&render->img, &render->vars, render->w, render->h);
	}
}

static int	init_graphics(int fractal_type)
{
	t_render	render;

	pre_init_graphics(&render);
	(&render)->type = fractal_type;
	if ((&render)->vars.mlx)
	{
		mlx_hook((&render)->vars.win, 2, 1L << 0, main_key_hook, &render);
		mlx_hook((&render)->vars.win, 4, 1L << 2, mouse_hook, &render);
		render_next_frame(&render);
		mlx_loop((&render)->vars.mlx);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (!init_graphics(check_params(argc, argv)))
	{
		ft_putstr("error: cannot initialize graphics.");
	}
	return (0);
}
