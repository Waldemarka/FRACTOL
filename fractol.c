/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:55:13 by vomelchu          #+#    #+#             */
/*   Updated: 2018/06/24 12:55:14 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		checkname(char *str, t_data *data)
{
	data->name_fract = 0;
	if (ft_atoi(str) >= 1 && ft_atoi(str) <= 5)
	{
		data->name_fract = ft_atoi(str);
		for_name(data->name_fract, data);
	}
	if (ft_strcmp(str, "MANDELBROT") == 0)
		data->name_fract = 1;
	else if (ft_strcmp(str, "JULIA") == 0)
		data->name_fract = 2;
	else if (ft_strcmp(str, "SIERPINSKI") == 0)
		data->name_fract = 3;
	else if (ft_strcmp(str, "SIEGLEDISK") == 0)
		data->name_fract = 4;
	else if (ft_strcmp(str, "SANMARCO") == 0)
		data->name_fract = 5;
	if (data->name_fract == 0)
		return (0);
	return (1);
}

int		key_down(int key, t_data *data)
{
	if (key == 24 || key == 69)
	{
		if (data->infinity < 200)
			data->infinity = data->infinity + 10;
	}
	else if (key == 27 || key == 78)
	{
		if (data->infinity > 25)
			data->infinity = data->infinity - 10;
	}
	else if (key == 49)
	{
		for_init(data);
		draw(data);
	}
	else if (key == 1)
		data->mov_m *= -1;
	else
		keys(key, data);
	draw(data);
	return (0);
}

int		main(int argc, char *argv[])
{
	t_data *data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		ft_error(1);
	data->name = argv[1];
	if (argc == 2 && checkname(data->name, data) != 0)
	{
		for_init(data);
		all_open(data);
		draw(data);
		mlx_hook(data->win, 2, 5, key_down, data);
		mlx_hook(data->win, 17, 1L << 17, exit_x, NULL);
		mlx_mouse_hook(data->win, zoom, data);
		mlx_hook(data->win, MOTION_NOTIFY, MOTION_MASK, moving_mod, data);
		mlx_loop(data->mlx);
	}
	else
		for_argv();
	return (0);
}
