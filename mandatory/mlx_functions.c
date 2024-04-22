/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 03:45:19 by ogcetin           #+#    #+#             */
/*   Updated: 2023/10/13 11:06:15 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_exit(void)
{
	exit(0);
	return (0);
}

static void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	mapper(int x, int y, t_cam *cam)
{
	t_complex	c;

	c.re = (((x - WINDOW_SIZE / 2) / cam->zoom) + cam->shift_x) / 200;
	c.im = (((WINDOW_SIZE / 2 - y) / cam->zoom) + cam->shift_y) / 200;
	cam->mapped = c;
}

void	put_cross_to_image(t_screen *s)
{
	int	o;

	o = WINDOW_SIZE / 2;
	if (s->cross % 2)
	{
		my_pixel_put(&(s->img), o - 2, o - 2, 0xFFFFFF);
		my_pixel_put(&(s->img), o + 2, o - 2, 0xFFFFFF);
		my_pixel_put(&(s->img), o - 1, o - 1, 0xFFFFFF);
		my_pixel_put(&(s->img), o + 1, o - 1, 0xFFFFFF);
		my_pixel_put(&(s->img), o, o, 0xFFFFFF);
		my_pixel_put(&(s->img), o - 1, o + 1, 0xFFFFFF);
		my_pixel_put(&(s->img), o + 1, o + 1, 0xFFFFFF);
		my_pixel_put(&(s->img), o - 2, o + 2, 0xFFFFFF);
		my_pixel_put(&(s->img), o + 2, o + 2, 0xFFFFFF);
	}
}

int	render(t_screen *s)
{
	int			x;
	int			y;
	int			i;

	y = 0;
	while (y < WINDOW_SIZE)
	{
		x = 0;
		while (x < WINDOW_SIZE)
		{
			s->cam.f_map(x, y, &(s->cam));
			i = s->f_iter(s);
			my_pixel_put(&(s->img), x, y, s->f_color(s->color1, s->color2, i));
			x++;
		}
		y++;
	}
	put_cross_to_image(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0, 0);
	return (0);
}
