/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:54:18 by roglopes          #+#    #+#             */
/*   Updated: 2023/11/12 16:20:16 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static int32_t	ft_bernstein_poly(uint32_t i, uint32_t iter_max)
{
	double		t;
	int32_t		color;

	t = 67.42 * i / iter_max;
	color = ft_pixel(255 * 15 * (1 - t) * (1 - t) * t * t, \
	255 * 9 * (1 - t) * t * t * t, \
	255 * 8.5 * + (1 - t) * (1 - t) * (1 - t) * t, 255);
	return (color);
}

static void	mandle_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name_fractal, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	uint32_t	color;
	int32_t		i;

	i = 0;
	z.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->axle_x;
	z.y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->axle_y;
	mandle_vs_julia(&z, &c, fractal);
	while (i < fractal->iterations_defintion)
	{
		z = sum_complex(square_complex(z), c);
		if (z.x * z.x + z.y * z.y > fractal->escape_valeu)
		{
			color = ft_bernstein_poly(i, fractal->iterations_defintion);
			mlx_put_pixel(fractal->mlx_fractal_screen, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fractal->mlx_fractal_screen, x, y, \
				ft_pixel(0x00, 0x00, 0x00, 0xFF));
}

int32_t	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	if (mlx_image_to_window(fractal->mlx_main_screen, \
							fractal->mlx_fractal_screen, 0, 0) == -1)
	{
		mlx_close_window(fractal->mlx_main_screen);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
