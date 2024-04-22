/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:53:18 by ogcetin           #+#    #+#             */
/*   Updated: 2023/10/13 23:32:45 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	setter(t_screen *s, int n)
{
	if (s->set_no != n)
	{
		s->set_no = n;
		s->cam.shift_x = 0;
		s->cam.shift_y = 0;
		s->cam.zoom = 0.8;
	}
}

static void	switch_set(int keycode, t_screen *s)
{
	if (keycode == KEY_1)
		setter(s, 1);
	else if (keycode == KEY_2)
	{
		setter(s, 2);
		s->input = (t_complex){0.3, 0.6};
	}
	else if (keycode == KEY_3)
		setter(s, 3);
	else if (keycode == KEY_4)
	{
		setter(s, 4);
		s->input = (t_complex){2, 1.1};
	}
	else if (keycode == KEY_5)
		setter(s, 5);
	else if (keycode == KEY_6)
		setter(s, 6);
	else if (keycode == KEY_7)
	{
		setter(s, 7);
		s->input = (t_complex){-1.5, -0.2};
	}
}

static void	handle_key2(int keycode, t_screen *s)
{
	if (keycode >= KEY_1 && keycode < KEY_8)
	{
		switch_set(keycode, s);
		set_iter_function(s);
	}
	if (keycode == KEY_LEFT || keycode == KEY_A)
		s->cam.shift_x -= WINDOW_SIZE / (MOVE_STEP * s->cam.zoom);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		s->cam.shift_x += WINDOW_SIZE / (MOVE_STEP * s->cam.zoom);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		s->cam.shift_y -= WINDOW_SIZE / (MOVE_STEP * s->cam.zoom);
	if (keycode == KEY_UP || keycode == KEY_W)
		s->cam.shift_y += WINDOW_SIZE / (MOVE_STEP * s->cam.zoom);
	if (keycode == KEY_STAR)
		handler(4, 0, 0, s);
	if (keycode == KEY_MINUS)
		handler(5, 0, 0, s);
}

int	handle_key(int keycode, t_screen *s)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_H)
	{
		mlx_put_image_to_window(s->mlx, s->win, s->img.img_help, 0, 0);
		s->help = ++s->help % 2;
	}
	if (s->help)
		return (0);
	if (keycode == KEY_C)
		s->cross++;
	if (keycode == KEY_R)
		init_data(s);
	if (keycode == KEY_SPACE)
	{
		s->flow_speed++;
		s->flow_speed = s->flow_speed % 2;
	}
	handle_key2(keycode, s);
	handler(0, 0, 0, s);
	return (0);
}
