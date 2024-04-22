/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_double_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:02:12 by ogcetin           #+#    #+#             */
/*   Updated: 2023/10/12 14:11:36 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	less_than_two_points(char *str)
{
	int	i;
	int	k;
	int	point;

	point = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			point++;
			k = i + 1;
			while (str[k] && str[k] != '.')
				k++;
			if (str[k] == '.')
				return (0);
		}
		i++;
	}
	if (point > 1)
		return (0);
	return (1);
}

static int	is_between_digits(char *str, int i)
{
	if (i == 0 || i == ft_strlen(str) - 1)
		return (0);
	return (is_digit(str[i - 1]) && is_digit(str[i + 1]));
}

int	is_double_formatted(char *d_str)
{
	int	i;

	if (!is_digit(d_str[0]) && ft_strlen(d_str) == 1)
		return (0);
	if (!less_than_two_points(d_str))
		return (0);
	i = 0;
	if (d_str[0] == '-')
		i++;
	while (d_str[i])
	{
		if (d_str[i] == '.' || is_digit(d_str[i]))
		{
			if (d_str[i] == '.' && !is_between_digits(d_str, i))
				return (0);
			i++;
		}
		else
			return (0);
	}
	return (1);
}
