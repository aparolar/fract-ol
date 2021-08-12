/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:21:07 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/12 14:48:36 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	new_image(t_data *img, t_vars *vars, int width, int height)
{
	img->img = mlx_new_image(vars->mlx, width, height);
	img->addr = mlx_get_data_addr(
			img->img,
			&img->bits_per_pixel,
			&img->line_length,
			&img->endian);
}
