/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:41:58 by ogcetin           #+#    #+#             */
/*   Updated: 2023/10/13 23:32:58 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int ac, char **av)
{
	t_screen	screen;

	check_input(ac, av, &screen);
	init_data(&screen);
	mlx_put_image_to_window(screen.mlx, screen.win, screen.img.img_help, 0, 0);
	mlx_hook(screen.win, 17, 1, &ft_exit, NULL);
	mlx_hook(screen.win, EVENT_KEY_PRESS, 1, &handle_key, &screen);
	mlx_mouse_hook(screen.win, &handle_mouse, &screen);
	mlx_loop_hook(screen.mlx, &color_flow, &screen);
	mlx_loop (screen.mlx);
	return (0);
}
