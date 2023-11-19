/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:47:16 by roglopes          #+#    #+#             */
/*   Updated: 2023/11/15 18:48:42 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief PROJECT
 *
 * Julia and Mandelbrot
 * Infinite Zoom
 * Able to take command line args to disipline which fractal render
 * Able to take command line args to shape Julia, i.e x y coordinates
 * ESC closes the process with no leaks
 * Click on the X window, closes the process leaks free
 *
 * 🚨 Code has to be norminetted 🚨
 * 		there are comments everywhere for clarity
 * 		i go always on the next line to better see the function inputs
*/
#ifndef FRACTOL_H
# define FRACTOL_H

/**
 * @brief Includes librarys for program.
 * 
 * @include stdio  -> puts;
 * @include stdlib -> exit failure and success;
 * @include unistd -> function write;
 * @include math   -> function mathematics;
 * @include MLX42  -> graphic rendering;
*/
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../../.library_mlx/MLX42/include/MLX42/MLX42.h"

/**
 * @brief Define for code.
 * 
 * @param WIDTH Screen;
 * @param HEIGHT Screen;
 * @param ERROR_MESSAGE So assist the user;
*/
# define WIDTH 800
# define HEIGHT 800
# define ERROR_MESSAGE "Please enter: \
						\n\t\"./fractol mandelbrot\" or \
						\n\t\"./fractol julia 0.285 +0\" \
						\n\t\"./fractol julia 0.285 +0.01\" \
						\n\t\"./fractol julia 0.45 +0.1428\" \
						\n\t\"./fractol julia -0.835 -0.232\" \
						\n\t\"./fractol julia −0.7269 +0.1889\" \
						\n\t\"./fractol julia 0.35 +0.35\" \
						\n\t\"./fractol julia 0.4 +0.4\" "

/**
 * @brief Complex valeu.
 * 
 * @param x Real number.
 * @param y Imaginary nunber. 
*/
typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

/**
 * @brief Used for some project definitions, such as
 *        screen, axis, zoom, iterations.
 * 
 * @see https://github.com/codam-coding-college/MLX42
 * 
 * @param name_fractal Name of the fractal that will be assingned by the user.
 * @param mlx_main_screen Return a pointer to the window we have just created.
 * @param mlx_fractal_screen Returnd new image to fractal.
 * @param escape_valeu Valeu hypotenuse 2² = 4 basically all the points are 
 *                     covered.
 * @param iterations_defintion The greater the number of iterations, the greater
 *                             the definition of the fractal.
 * NOTE: It is advisable to use a maximum oof 100, due to the machine's
 *       processing, but if you wanted to test with 1000.
 * @param axle_x Axle x for left and right side movement.
 * @param axle_y Axle y for up and donw side movement.
 * @param zoom Zoom in and out of the fractal.
 * @param julia_x Receives the first argument for creating the fractal julia.
 * @param julia_y Receives the second argument for creating the fractal julia. 
*/
typedef struct s_fractal
{
	char	*name_fractal;
	void	*mlx_main_screen;
	void	*mlx_fractal_screen;
	double	escape_valeu;
	int		iterations_defintion;
	double	axle_x;
	double	axle_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;

/**
 * @brief Calculates the length of the string pointed to by 'argument',
 * before the terminating null byte ('\0') can be found.
 * 
 * @param argument as a true C string, terminated by '\0'
 * @return The number of chars in the string.
*/
size_t		ft_strlen(const char *argument);

/**
 * @brief Compares only the first (at most) n bytes of two strings,
 * 's1' and 's2'.
 * 
 * @param s1 a string
 * @param s2 a string
 * @param the amount of bytes to compair
 * @return An integer less than, equal to, or greater than 
 * zero if 's1' is found, respectively, to be less than, to match, 
 * or be greater than 's2'.
*/
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Outputs the string 's' to the given file descriptor.
 * 
 * @param s the string to output
 * @param fd the file descriptor on which to write
*/
void		ft_putstr_fd(char *s, int fd);

/**
 * @brief Converts the initial portion of the string pointed to by 
 * 'nptr' to int.
 * 
 * @param nptr a string to convert
 * @return int with the converted value.
*/
double		ft_atoidbl(const char *nptr);

/**
 * @brief Creation of screens and initialization of variables necessary
 * for the project.
 * 
 * @param fractal struct for creating screens.
 * @return EXIT_FAILURE if the creation of the screens did not work.
 * @return EXIT_SUCCESS if the creation of the screens worked.
*/
int32_t		fractal_init(t_fractal *fractal);

/**
 * @brief Cycles through height and width to fill the pixels on the screen
 * 
 * @param fractal struct for render the pixels.
 * @return EXIT_FAILURE if the creation of the screens did not work.
 * @return EXIT_SUCCESS if the creation of the screens worked.
*/
int32_t		fractal_render(t_fractal *fractal);

/**
 * @brief Move the fractal up, down, left and , right, with arrows.
 * 
 * @param param Additional parameter to pass on to the function.
*/
void		ft_movement_handler(void *param);

/**
 * @brief Callback function used to handle scrolling.
 * 
 * @param xdelta The mouse x delta.
 * @param ydelta The mouse y delta.
 * @param param Additional parameter to pass on to the function.
 */
void		ft_mouse_handler(double xdelta, double ydelta, void *param);

/**
 * @brief Resizing canvas scale from 800x800 to -2x2.
 * 
 * @param unscaled_num Type of number double.
 * @param new_min Minimum number for resizing.
 * @param new_max Maximum number for resizing.
 * @param old_max Size of the scale that will be transformed.
 * 
 * @return Resizing calculation.
*/
double		map(double unscaled_num, double new_min, double new_max, \
			double old_max);

/**
 * @brief Sum complex, is vector addition
 * 
 * @param z1 Vector X.
 * @param z2 Vector Y.
 * 
 * @return Sum the vector x and vector y.
*/
t_complex	sum_complex(t_complex z1, t_complex z2);

/**
 * @brief Square is trickier.
 * 
 * @param z For calculation.
 * 
 * @return 
 * Z_real = z_real*z_real – z_imaginary*z_imaginary + c_real
 * Z_imaginary = 2*z_real*z_imaginary + c_imaginary.
*/
t_complex	square_complex(t_complex z);
#endif