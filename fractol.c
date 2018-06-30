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
	else if (ft_strcmp(str, "SIERPINSKI_CARPET") == 0)
		data->name_fract = 3;
	if (data->name_fract == 0)
		return (0);
	return (1);
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
		mlx_loop(data->mlx);
	}
	else
		for_argv();
	return 0;
}
