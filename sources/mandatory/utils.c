/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:53:01 by roglopes          #+#    #+#             */
/*   Updated: 2023/11/07 21:14:26 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(const char *argument)
{
	unsigned int	count;

	count = 0;
	while (argument[count] != '\0')
		count++;
	return (count);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	length;

	length = 0;
	while ((s1[length] != '\0' || s2[length] != '\0') && length < n)
	{
		if (s1[length] != s2[length])
			return ((unsigned char) s1[length] - (unsigned char) s2[length]);
		length++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

double	ft_atoidbl(const char *nptr)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*nptr >= 9 && *nptr <= 13) || 32 == *nptr)
		++nptr;
	while ('+' == *nptr || '-' == *nptr)
		if ('-' == *nptr++)
			sign = -sign;
	while (*nptr != '.' && *nptr)
		integer_part = (integer_part * 10) + (*nptr++ - 48);
	if ('.' == *nptr)
		++nptr;
	while (*nptr)
	{
		pow /= 10;
		fractional_part = fractional_part + (*nptr++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
