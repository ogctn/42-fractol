/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_function2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:18:35 by ogcetin           #+#    #+#             */
/*   Updated: 2023/10/13 19:51:17 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iter_spiral(t_screen *s)
{
	t_complex	z;
	t_complex	c;
	int			iter;

	iter = 0;
	z = s->cam.mapped;
	c = s->input;
	while (squared_add(z.re, z.im, '+') <= 4 && iter < MAX_ITER)
	{
		z = (t_complex){z.re * cos(z.re) - z.im * sin(z.im) + c.re,
			z.re * sin(z.re) + z.im * cos(z.im) + c.im};
		iter++;
	}
	return (iter);
}

int	iter_burning_ship(t_screen *s)
{
	t_complex	c;
	t_complex	z;
	int			iter;

	iter = 0;
	z = s->cam.mapped;
	c = z;
	while (squared_add(z.re, z.im, '+') <= 4 && iter < MAX_ITER)
	{
		z = (t_complex){squared_add(fabs(z.re), fabs(z.im), '-') + c.re,
			-2 * fabs(z.re) * fabs(z.im) + c.im};
		iter++;
	}
	return (iter);
}

int	iter_phoenix(t_screen *s)
{
	t_complex	z;
	t_complex	c;
	int			iter;

	iter = 0;
	z = s->cam.mapped;
	c = s->input;
	while (squared_add(z.re, z.im, '+') <= 4 && iter < MAX_ITER)
	{
		z = (t_complex){fabs(z.re * z.re - z.im * z.im) + c.re,
			2 * z.re * z.im + c.im};
		iter++;
	}
	return (iter);
}
