/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:26:41 by ogcetin           #+#    #+#             */
/*   Updated: 2023/10/13 23:32:41 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	usage(void)
{
	ft_putstr("---------------\nUsage: ");
	ft_putstr("./fractol <[F]ractalName>\n\n");
	ft_putstr("Example: ./fractol M\n\n");
	ft_putstr(VALID_FRACS);
	exit(1);
}

int	is_valid_set(char *set)
{
	return (!(ft_strcmp(set, "M") && ft_strcmp(set, "J")
			&& ft_strcmp(set, "C") && ft_strcmp(set, "S")
			&& ft_strcmp(set, "T") && ft_strcmp(set, "B")
			&& ft_strcmp(set, "P")));
}

static void	set_set_no(char *set, t_screen *s)
{
	if (!ft_strcmp(set, "M"))
		s->set_no = 1;
	if (!ft_strcmp(set, "J"))
		s->set_no = 2;
	if (!ft_strcmp(set, "C"))
		s->set_no = 3;
	if (!ft_strcmp(set, "S"))
		s->set_no = 4;
	if (!ft_strcmp(set, "T"))
		s->set_no = 5;
	if (!ft_strcmp(set, "B"))
		s->set_no = 6;
	if (!ft_strcmp(set, "P"))
		s->set_no = 7;
}

void	check_input(int ac, char **av, t_screen *s)
{
	int	err;

	err = 0;
	if (ac < 2 || !is_valid_set(av[1]))
		usage();
	else if (ac > 1 && !is_valid_set(av[1]))
		err = ft_putstr(VALID_FRACS);
	else if (ac < 4 && !(ft_strcmp(av[1], "J") && ft_strcmp(av[1], "P") \
	&& ft_strcmp(av[1], "S")))
	{
		err = ft_putstr("Needs 2 parameters!\n");
		ft_putstr("Example: ./fractol {J,P,S} 0.6 0.55\n");
	}
	else if (ac == 4 && (!ft_strcmp(av[1], "J") || (!ft_strcmp(av[1], "P"))))
	{
		if (!is_double_formatted(av[2]) || !is_double_formatted(av[3]))
			err = ft_putstr("Parameters should be double!\nExample: -0.55\n");
		s->input.re = ft_atod(av[2]);
		s->input.im = ft_atod(av[3]);
	}
	if (err)
		exit(1);
	set_set_no(av[1], s);
}
