/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:35:03 by roglopes          #+#    #+#             */
/*   Updated: 2023/11/19 12:31:38 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractal *fractal)
{
	fractal->escape_valeu = 4;
	fractal->iterations_defintion = 1000;
	fractal->axle_x = 0.0;
	fractal->axle_y = 0.0;
	fractal->zoom = 1.0;
}

void	ft_movement_handler(void *param)
{
	t_fractal	*fractal;

	fractal = param;
	if (mlx_is_key_down(fractal->mlx_main_screen, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx_main_screen);
	else if (mlx_is_key_down(fractal->mlx_main_screen, MLX_KEY_LEFT))
		fractal->axle_x += (0.5 * fractal->zoom);
	else if (mlx_is_key_down(fractal->mlx_main_screen, MLX_KEY_RIGHT))
		fractal->axle_x -= (0.5 * fractal->zoom);
	else if (mlx_is_key_down(fractal->mlx_main_screen, MLX_KEY_UP))
		fractal->axle_y -= (0.5 * fractal->zoom);
	else if (mlx_is_key_down(fractal->mlx_main_screen, MLX_KEY_DOWN))
		fractal->axle_y += (0.5 * fractal->zoom);
	fractal_render(fractal);
}

void	ft_mouse_handler(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	if (ydelta > 0)
	{
		fractal->zoom *= 0.95;
	}
	else if (xdelta < 0)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
}

int32_t	fractal_init(t_fractal *fractal)
{
	fractal->mlx_main_screen = mlx_init(WIDTH, HEIGHT, \
										fractal->name_fractal, true);
	if (NULL == fractal->mlx_main_screen)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	fractal->mlx_fractal_screen = mlx_new_image(fractal->mlx_main_screen, \
										WIDTH, HEIGHT);
	if (NULL == fractal->mlx_fractal_screen)
	{
		mlx_close_window(fractal->mlx_main_screen);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	data_init(fractal);
	return (EXIT_SUCCESS);
}
