/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:18:04 by ogcetin           #+#    #+#             */
/*   Updated: 2023/10/13 21:26:31 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	two_colors(int c1, int c2, int i)
{
	if (i % 10 > 5)
		return (c1);
	return (c2);
}

static double	linear_interpolation(double a, double b, double t)
{
	return ((1 - t) * a + t * b);
}

int	multi_color(int c1, int c2, int i)
{
	int		c[3];
	double	t;

	if (i == MAX_ITER)
		return (c2);
	t = (double)i / MAX_ITER;
	c[0] = (unsigned char)linear_interpolation(c1, c2, t);
	c[1] = ((unsigned char)linear_interpolation(c1 >> 8, c2 >> 8, t));
	c[2] = ((unsigned char)linear_interpolation(c1 >> 16, c2 >> 16, t));
	return ((c[0] << 16) | (c[1] << 8) | c[2]);
}

int	smooth_colored(int cc1, int cc2, int i)
{
	int		c1[3];
	int		c2[3];
	int		c[3];
	double	t;

	if (i < MAX_ITER)
	{
		c1[0] = (cc1 >> 16) & 0xFF;
		c1[1] = (cc1 >> 8) & 0xFF;
		c1[2] = cc1 & 0xFF;
		c2[0] = (cc2 >> 16) & 0xFF;
		c2[1] = (cc2 >> 8) & 0xFF;
		c2[2] = cc2 & 0xFF;
		t = (double)i / MAX_ITER;
		c[0] = (int)(7 * (1 - t) * t * t * t * (c2[0] - c1[0])) + c1[0];
		c[1] = (int)(7 * (1 - t) * (1 - t) * t * t * (c2[1] - c1[1])) + c1[1];
		c[2] = (int)(7 * (1 - t) * (1 - t) * (1 - t) * t * (c2[2] - c1[2])) \
	+ c1[2];
		return ((c[0] << 16) | (c[1] << 8) | c[2]);
	}
	else
		return (cc2);
}

int	potential_coloring(int c1, int c2, int i)
{
	int	c[3];

	if (i == MAX_ITER)
		return (c2);
	c[0] = (i * ((c1 >> 16) & 0xFF)) / MAX_ITER;
	c[1] = (i * ((c1 >> 8) & 0xFF)) / MAX_ITER;
	c[2] = (i * (c1 & 0xFF)) / MAX_ITER;
	return ((c[0] << 16) | (c[1] << 8) | c[2]);
}
