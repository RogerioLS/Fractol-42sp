/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:02:19 by roglopes          #+#    #+#             */
/*   Updated: 2023/11/19 16:49:53 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	map(double unscaled_num, double new_min, double new_max, \
			double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0) / \
	(old_max - 0) + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z, t_fractal *fractal)
{
	t_complex	result;

	if (!ft_strncmp(fractal->name_fractal, "tricorn", 7))
	{
		result.x = (z.x * z.x) - (z.y * z.y);
		result.y = -2 * z.x * z.y;
	}
	else
	{
		result.x = (z.x * z.x) - (z.y * z.y);
		result.y = 2 * z.x * z.y;
	}
	return (result);
}
