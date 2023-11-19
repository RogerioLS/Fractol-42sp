/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:26:24 by roglopes          #+#    #+#             */
/*   Updated: 2023/11/12 19:49:38 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	main(int32_t argc, char *argv[])
{
	t_fractal	fractal;

	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10)) \
	|| (4 == argc && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name_fractal = argv[1];
		if (!ft_strncmp(fractal.name_fractal, "julia", 5))
		{
			fractal.julia_x = ft_atoidbl(argv[2]);
			fractal.julia_y = ft_atoidbl(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop_hook(fractal.mlx_main_screen, ft_movement_handler, &fractal);
		mlx_scroll_hook(fractal.mlx_main_screen, ft_mouse_handler, &fractal);
		mlx_loop(fractal.mlx_main_screen);
		mlx_terminate(fractal.mlx_main_screen);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
}
