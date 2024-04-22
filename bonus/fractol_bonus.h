/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 23:51:12 by ogcetin           #+#    #+#             */
/*   Updated: 2023/10/13 23:33:22 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "keys_bonus.h"
# include "../mlx/mlx.h"

# define WINDOW_SIZE 640
# define MAX_ITER 200
# define MIN_ZOOM 0.2
# define ZOOM_STEP 1.2
# define MOVE_STEP 15

typedef struct s_img
{
	void	*img;
	void	*img_help;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_cam	t_cam;

typedef struct s_cam
{
	double			shift_x;
	double			shift_y;
	double			zoom;
	unsigned int	i;
	t_complex		mapped;
	void			(*f_map)(int, int, t_cam *);
}	t_cam;

typedef struct s_screen	t_screen;

typedef struct s_screen
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_complex	point;
	t_cam		cam;
	t_complex	input;
	int			(*f_iter)(t_screen *);
	int			(*f_color)(int, int, int);
	int			set_no;
	int			cross;
	int			color1;
	int			color2;
	int			lb;
	int			rb;
	int			help;
	int			flow_speed;
}	t_screen;

int		is_digit(char c);
int		ft_strlen(char *s);
int		is_double_formatted(char *d_str);
int		ft_strcmp(char *s1, char *s2);
int		ft_putstr(char *str);
int		ft_exit(void);

double	ft_atod(char *str);
void	check_input(int ac, char **av, t_screen *s);
void	mapper(int x, int y, t_cam *cam);
void	init_data(t_screen *screen);

double	squared_add(double a, double b, char flag);
int		iter_mandel(t_screen *s);
int		iter_julia(t_screen *s);
int		iter_celtic(t_screen *s);
int		iter_spiral(t_screen *s);
int		iter_tricorn(t_screen *s);
int		iter_burning_ship(t_screen *s);
int		iter_phoenix(t_screen *s);
void	set_iter_function(t_screen *s);

int		render(t_screen *s);
void	put_cross_to_image(t_screen *s);

int		two_colors(int c1, int c2, int i);
int		multi_color(int c1, int c2, int i);
int		smooth_colored(int cc1, int cc2, int i);
int		potential_coloring(int c1, int c2, int i);
int		color_flow(t_screen *s);

int		handle_key(int keycode, t_screen *s);
int		handle_mouse(int keycode, int x, int y, t_screen *s);
void	handler(int keycode, int x, int y, t_screen *s);

int		handle_button_press(int button, t_screen *s);
int		handle_button_release(int button, t_screen *s);
int		increment_variable(t_screen *s);

#endif
