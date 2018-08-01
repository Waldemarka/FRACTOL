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
#include <stdio.h>

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
	else if (ft_strcmp(str, "SIERPINSKI_CARPET") == 0)
		data->name_fract = 3;
	if (data->name_fract == 0)
		return (0);
	return (1);
}
/*
void	strings(t_data *data)
{
	data->str *= (-1);
	if (data->str == 1)
	{
		mlx_string_put(data->mlx, data->win, 20, 10, 0xE5AA70,
		"COLOR: 1 || 2 || 3");
		mlx_string_put(data->mlx, data->win, 20, 30, 0xE5AA70,
		"ZOOM: Mouse || + || -");
		mlx_string_put(data->mlx, data->win, 20, 30, 0xE5AA70,
		"RESET: Space");
		mlx_string_put(data->mlx, data->win, 20, 30, 0xE5AA70,
		"MOVING: ← ↑ → ↓");
		mlx_string_put(data->mlx, data->win, 20, 30, 0xE5AA70,
		"ADVICE (HIDE/SHOW): ctrl");
	}
	draw(data);
}
*/
int 	key_down(int key, t_data *data)
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
/*	else if (key == 256)
		strings(data);*/
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
		mlx_loop(data->mlx);
	}
	else
		for_argv();
	return 0;
}
