/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:15:38 by ogcetin           #+#    #+#             */
/*   Updated: 2023/10/13 23:32:51 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	is_whitespace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\f' || c == '\v')
		return (1);
	return (0);
}

static int	read_units(char *str, int i, double *result)
{
	while (str[i] && is_digit(str[i]))
	{
		*result *= 10;
		*result += str[i] - 48;
		i++;
	}
	return (i);
}

static double	read_decimals(char *str, int i)
{
	int		decimal_power;
	double	result;
	double	tmp;

	decimal_power = 0;
	result = 0.0;
	while (str[i] && is_digit(str[i]))
	{
		decimal_power++;
		tmp = (double)(str[i] - 48) / pow(10, decimal_power);
		result += tmp;
		i++;
	}
	return (result);
}

double	ft_atod(char *str)
{
	unsigned int	i;
	double			result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] && is_whitespace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	i = read_units(str, i, &result);
	if (str[i] == '.')
		result += read_decimals(str, i + 1);
	return (result * sign);
}
