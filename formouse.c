/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 10:52:49 by vomelchu          #+#    #+#             */
/*   Updated: 2018/07/31 10:52:51 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		outzoom(t_data *data, long double stex, long double stey)
{
	if (data->zoom > 2.0)
		return (0);
	data->zoom *= 1.1f;
	data->min_x = data->min_x * 1.2 + stex * -0.2;
	data->max_x = data->max_x * 1.2 + stex * -0.2;
	data->min_y = data->min_y * 1.2 + stey * -0.2;
	data->max_y = data->max_y * 1.2 + stey * -0.2;
	return (0);
}

int		inzoom(t_data *data, long double stex, long double stey)
{
	data->zoom *= 0.8f;
	data->min_x = data->min_x * 0.8 + stex * 0.2;
	data->max_x = data->max_x * 0.8 + stex * 0.2;
	data->min_y = data->min_y * 0.8 + stey * 0.2;
	data->max_y = data->max_y * 0.8 + stey * 0.2;
	return (0);
}

int 	zoom(int key, int x, int y, t_data *data)
{
	long double widtx;
	long double heighty;
	long double stex;
	long double stey;

	widtx = data->max_x - data->min_x;
	heighty = data->max_y - data->min_y;
	stex = data->min_x + ((long double)x * widtx / (long double)WIDTH);
	stey = data->min_y + ((long double)y * heighty / (long double)HEIGHT);
	if (key == 5)
		inzoom(data, stex, stey);
	if (key == 4)
		outzoom(data, stex, stey);
	draw(data);
	return (0);
}

int		last(int key, t_data *data)
{
	if (key == 83)
		zoom(5, (long double)WIDTH/2, (long double)HEIGHT/2, data);
	else if (key == 82)
		zoom(4, (long double)WIDTH/2, (long double)HEIGHT/2, data);
	else if (key == 18)
	{
		data->color1 = 113;
		data->color2 = 231;
		data->color3 = 312;
	}
	else if (key == 19)
	{
		data->color1 = 230;
		data->color2 = 230;
		data->color3 = 230;
	}
	else if (key == 20)
	{
		data->color1 = 1;
		data->color2 = 4;
		data->color3 = 7;
	}
	return (0);
}

int 	keys(int key, t_data *data)
{
	if (key == 123 && data->min_x > -1.5)
	{
		data->min_x -= ((data->max_x - data->min_x) / 10.0);
		data->max_x -= ((data->max_x - data->min_x) / 10.0);
	}
	else if (key == 124 && data->max_x < 1.0)
	{
		data->min_x += ((data->max_x - data->min_x) / 10.0);
		data->max_x += ((data->max_x - data->min_x) / 10.0);
	}
	else if (key == 126 && data->min_y > -1.0)
	{
		data->min_y -= ((data->max_y - data->min_y) / 10.0);
		data->max_y -= ((data->max_y - data->min_y) / 10.0);
	}
	else if (key == 125 && data->max_x < 1.0)
	{
		data->min_y += ((data->max_y - data->min_y) / 10.0);
		data->max_y += ((data->max_y - data->min_y) / 10.0);
	}
	else if (key == 53)
		exit_x();
	else
		last(key, data);
	return (0);
}