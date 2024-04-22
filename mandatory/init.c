/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:56:44 by ogcetin           #+#    #+#             */
/*   Updated: 2023/10/13 23:24:42 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mlxs(t_screen *s)
{
	int	w;

	w = WINDOW_SIZE;
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, WINDOW_SIZE, WINDOW_SIZE, "Fractol");
	s->img.img = mlx_new_image(s->mlx, WINDOW_SIZE, WINDOW_SIZE);
	s->img.addr = mlx_get_data_addr(s->img.img, &(s->img.bpp),
			&(s->img.line_len), &(s->img.endian));
	s->img.img_help = mlx_xpm_file_to_image(s->mlx, HELP_DIR, &w, &w);
}

void	set_iter_function(t_screen *s)
{
	if (s->set_no == 1)
		s->f_iter = &iter_mandel;
	else if (s->set_no == 2)
		s->f_iter = &iter_julia;
	else if (s->set_no == 3)
		s->f_iter = &iter_celtic;
	else if (s->set_no == 4)
		s->f_iter = &iter_spiral;
	else if (s->set_no == 5)
		s->f_iter = &iter_tricorn;
	else if (s->set_no == 6)
		s->f_iter = &iter_burning_ship;
	else if (s->set_no == 7)
		s->f_iter = &iter_phoenix;
}

void	init_data(t_screen *screen)
{
	static int	i = 0;

	if (!i++)
	{
		init_mlxs(screen);
		screen->cam.f_map = &mapper;
		screen->f_color = &potential_coloring;
		screen->help = 1;
	}
	set_iter_function(screen);
	screen->cam.shift_x = 0;
	screen->cam.shift_y = 0;
	screen->cam.zoom = 0.8;
	screen->color1 = 0xD0D3D4;
	screen->color2 = 0x58D68D;
	screen->lb = 0;
	screen->rb = 0;
	screen->flow_speed = 0;
}
