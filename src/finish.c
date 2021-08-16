/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:40:57 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/16 10:41:43 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	free_all(t_render *render)
{
	mlx_destroy_image(render->vars.mlx, render->img.img);
	mlx_destroy_window(render->vars.mlx, render->vars.win);
	if (OS == 'l')
		mlx_destroy_display(render->vars.mlx);
	free(render->vars.mlx);
	exit(0);
}
