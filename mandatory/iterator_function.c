/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:40:59 by ogcetin           #+#    #+#             */
/*   Updated: 2023/10/13 12:18:53 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	dabs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	iter_mandel(t_screen *s)
{
	t_complex	c;
	t_complex	z;
	int			iter;

	iter = 0;
	z = s->cam.mapped;
	c = z;
	while (squared_add(z.re, z.im, '+') <= 4 && iter < MAX_ITER)
	{
		z = (t_complex){squared_add(z.re, z.im, '-') + c.re,
			2 * z.re * z.im + c.im};
		iter++;
	}
	return (iter);
}

int	iter_julia(t_screen *s)
{
	t_complex	c;
	t_complex	z;
	int			iter;

	iter = 0;
	z = s->cam.mapped;
	c = s->input;
	while (squared_add(z.re, z.im, '+') <= 4 && iter < MAX_ITER)
	{
		z = (t_complex){squared_add(z.re, z.im, '-') + c.re,
			2 * z.re * z.im + c.im};
		iter++;
	}
	return (iter);
}

int	iter_celtic(t_screen *s)
{
	t_complex	z;
	t_complex	c;
	int			iter;

	iter = 0;
	z = s->cam.mapped;
	c = z;
	while ((squared_add(z.re, z.im, '+') <= 4 && iter < MAX_ITER))
	{
		z = (t_complex){dabs((z.re * dabs(z.re)) + (z.im * z.im)) + c.re,
			(z.re * z.im * 2) + c.im};
		iter++;
	}
	return (iter);
}

int	iter_tricorn(t_screen *s)
{
	t_complex	z;
	t_complex	c;
	int			iter;

	iter = 0;
	z = s->cam.mapped;
	c = z;
	while (squared_add(z.re, z.im, '+') <= 4 && iter < MAX_ITER)
	{
		z = (t_complex){dabs((z.re * z.re) - (z.im * z.im)) + c.re,
			(-2 * z.re * z.im) + c.im};
		iter++;
	}
	return (iter);
}
