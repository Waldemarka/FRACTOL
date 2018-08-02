/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 15:44:02 by vomelchu          #+#    #+#             */
/*   Updated: 2018/06/24 15:44:03 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	ft_error(int q)
{
	if (q == 1)
		ft_putstr("Bad Malloc");
	if (q == 2)
		ft_putstr("Bad Opening Window!");
	exit(0);
}

void	for_name(int i, t_data *data)
{
	if (i == 1)
		data->name = "MANDELBROT";
	if (i == 2)
		data->name = "JULIA";
	if (i == 3)
		data->name = "SIERPINSKI";
	if (i == 4)
		data->name = "SIEGLE DISK";
	if (i == 5)
		data->name = "SAN MARCO";
}

LD		coord(LD x, LD widt, LD min, LD max)
{
	LD ret;

	ret = min + (max - min) * ((x - 0) / (widt - 0));
	return (ret);
}

void	for_argv(void)
{
	ft_putstr("List of available parameters:\n");
	ft_putstr("1: MANDELBROT\n");
	ft_putstr("2: JULIA\n");
	ft_putstr("3: SIERPINSKI\n");
	ft_putstr("4: SIEGLE DISK\n");
	ft_putstr("5: SAN MARCO\n");
}

int		exit_x(void)
{
	exit(1);
	return (0);
}
