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

int 		make_and_put(t_data *data, int x, int y)
{
	if (data->iter == data->infinity)
	{
		data->col_imag[INDEX + 2] = 0;  
		data->col_imag[INDEX + 1] = 0;
		data->col_imag[INDEX] = 0;
	}
	else
		data->col_imag[INDEX + 2] = data->iter * data->color1 % 225;  
		data->col_imag[INDEX] = data->iter * data->color2 % 225;
		data->col_imag[INDEX + 1] = data->iter * data->color3 % 225;
	return (0);
}

long double		coord(long double x, long double i, long double widt, long double min, long double max)
{
	long double ret;

	ret = min + (max - min) * ((x - i) / (widt - i));
	return (ret);
}

int			mandel(t_data *data, int x, int y)
{
	long double mx;
	long double my;
	long double c_im;
	long double c_re;
	long double x_temp;

	data->iter = 0;
	mx = 0.0;
	my = 0.0;
	c_re = coord(x,0, WIDTH, data->min_x, data->max_x);
	c_im = coord(y, 0, HEIGHT, data->min_y, data->max_y);
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

int			julia(t_data *data, int x, int y)
{
	long double mx;
	long double my;
	long double c_im;
	long double c_re;
	long double x_temp;

	data->iter = 0;
	c_re = -0.70176;
	c_im = -0.3842;
	
	mx = coord(x,0, WIDTH, data->min_x, data->max_x);
	my = coord(y, 0, HEIGHT, data->min_y, data->max_y);
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

int		sierp(t_data *data, int x, int y)
{
	int i;
	float zoom;

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