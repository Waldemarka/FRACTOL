/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractalhciki.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:26:48 by vomelchu          #+#    #+#             */
/*   Updated: 2018/06/27 16:26:50 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		mandel(t_data *data, int x, int y)
{
	long double mx;
	long double my;
	long double c_im;
	long double c_re;
	long double x_temp;

	data->iter = 0;
	mx = 0.0;
	my = 0.0;
	c_re = coord(x, WIDTH, data->min_x, data->max_x);
	c_im = coord(y, HEIGHT, data->min_y, data->max_y);
	while (data->iter < data->infinity)
	{
		x_temp = (mx * mx - my * my) + c_re;
		my = 2.0 * mx * my + c_im;
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0)
			break ;
		data->iter++;
	}
	return (data->iter);
}

int		julia(t_data *data, int x, int y)
{
	long double mx;
	long double my;
	long double x_temp;

	data->iter = 0;
	mx = coord(x, WIDTH, data->min_x, data->max_x);
	my = coord(y, HEIGHT, data->min_y, data->max_y);
	while (data->iter < data->infinity)
	{
		x_temp = (mx * mx - my * my) + data->cord1;
		my = 2.0 * mx * my + data->cord2;
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0)
			break ;
		data->iter++;
	}
	return (data->iter);
}

int		sierpinski(t_data *data, int x, int y)
{
	int			i;
	long double	zoom;

	i = 0;
	zoom = data->zoom;
	x *= zoom;
	y *= zoom;
	while (i < data->infinity)
	{
		if ((x % 3 == 1) && (y % 3 == 1))
			return (data->iter = 0);
		x /= 3;
		y /= 3;
		i++;
	}
	return (data->iter = 60);
}

int		siegle(t_data *data, int x, int y)
{
	long double mx;
	long double my;
	long double c_im;
	long double c_re;
	long double x_temp;

	data->iter = 0;
	c_re = -0.390541;
	c_im = -0.586788;
	mx = coord(x, WIDTH, data->min_x, data->max_x);
	my = coord(y, HEIGHT, data->min_y, data->max_y);
	while (data->iter < data->infinity)
	{
		x_temp = (mx * mx - my * my) + c_re;
		my = 2.0 * mx * my + c_im;
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0)
			break ;
		data->iter++;
	}
	return (data->iter);
}

int		san_marco(t_data *data, int x, int y)
{
	long double mx;
	long double my;
	long double c_im;
	long double c_re;
	long double x_temp;

	data->iter = 0;
	c_re = -0.75;
	c_im = 0;
	mx = coord(x, WIDTH, data->min_x, data->max_x);
	my = coord(y, HEIGHT, data->min_y, data->max_y);
	while (data->iter < data->infinity)
	{
		x_temp = (mx * mx - my * my) + c_re;
		my = 2.0 * mx * my + c_im;
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0)
			break ;
		data->iter++;
	}
	return (data->iter);
}
