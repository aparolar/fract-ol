/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:10:14 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/12 14:48:30 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	create_color(int i)
{
	int	r;
	int	g;
	int	b;

	r = sin(0.1 * i + 0) * 127 + 128;
	g = sin(0.1 * i + 2 * M_PI / 3) * 127 + 128;
	b = sin(0.1 * i + 4 * M_PI / 3) * 127 + 128;
	return (create_trgb(0, r, g, b));
}
