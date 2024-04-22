/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:05:56 by ogcetin           #+#    #+#             */
/*   Updated: 2023/10/13 23:32:47 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	change_color_method(t_screen *s)
{
	static int	i = 1;

	if (s->help)
		return ;
	if (i == 0)
		s->f_color = &two_colors;
	else if (i == 1)
		s->f_color = &multi_color;
	else if (i == 2)
		s->f_color = &smooth_colored;
	else if (i == 3)
	{
		s->f_color = &potential_coloring;
		i = -1;
	}
	i++;
	handler(0, 0, 0, s);
}

int	handle_mouse(int keycode, int x, int y, t_screen *s)
{
	static int	left_button_pressed = 0;
	static int	right_button_pressed = 0;

	if (s->help)
		return (0);
	if (keycode == M_SCROLL_DOWN || keycode == M_SCROLL_UP)
		handler(keycode, x - WINDOW_SIZE / 2, WINDOW_SIZE / 2 - y, s);
	if (keycode == M_BUTTON_1)
	{
		left_button_pressed = left_button_pressed % 2;
		s->lb = ++left_button_pressed;
	}
	if (keycode == M_BUTTON_2)
	{
		right_button_pressed = right_button_pressed % 2;
		s->rb = ++right_button_pressed;
	}
	if (keycode == M_BUTTON_3)
		change_color_method(s);
	return (1);
}

int	color_flow(t_screen *s)
{
	static int	time = 0;
	int			speed;

	speed = 1000;
	if (!s->flow_speed)
		speed = 10000;
	time = time % speed;
	if (!(time % speed))
	{
		if (!s->help)
		{
			if (s->color1 >= 0xFFFFFF)
				s->color1 = 0x000FFF;
			if (s->color2 <= 0x000000)
				s->color2 = 0xFFF000;
			if (s->rb % 2)
				s->color1 -= 0x000FFF;
			if (s->lb % 2)
				s->color2 += 0x000FFF;
			handler(0, 0, 0, s);
		}
	}
	time++;
	return (0);
}

void	handler(int keycode, int x, int y, t_screen *s)
{
	if (keycode == 4)
	{
		s->cam.zoom *= 2;
		s->cam.shift_x += x / s->cam.zoom;
		s->cam.shift_y += y / s->cam.zoom;
	}
	if (keycode == 5)
	{
		if (s->cam.zoom > MIN_ZOOM)
			s->cam.zoom /= 2;
	}
	render(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0, 0);
}
