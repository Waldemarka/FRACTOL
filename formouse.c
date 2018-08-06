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

int		zoom(int key, int x, int y, t_data *data)
{
	long double stex;
	long double stey;
	long double koef;

	koef = 0.0;
	stex = data->min_x + ((long double)x * WIDTX / (long double)WIDTH);
	stey = data->min_y + ((long double)y * HEIGY / (long double)HEIGHT);
	if (key == 5 || key == 4)
	{
		if (key == 5)
		{
			koef = 1.1;
			if (data->zoom > 2.0)
				return (0);
		}
		else if (key == 4)
			koef = 0.9;
		data->zoom *= koef;
		data->min_x = data->min_x * koef + stex * (1 - koef);
		data->max_x = data->max_x * koef + stex * (1 - koef);
		data->min_y = data->min_y * koef + stey * (1 - koef);
		data->max_y = data->max_y * koef + stey * (1 - koef);
	}
	draw(data);
	return (0);
}

int		last(int key, t_data *data)
{
	if (key == 83)
		zoom(5, (long double)WIDTH / 2, (long double)HEIGHT / 2, data);
	else if (key == 82)
		zoom(4, (long double)WIDTH / 2, (long double)HEIGHT / 2, data);
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

int		moving_mod(int x, int y, t_data *data)
{
	if (data->mov_m == -1)
	{
		data->cord1 = coord(x, WIDTH, data->min_x, data->max_x);
		data->cord2 = coord(y, HEIGHT, data->min_y, data->max_y);
		draw(data);
	}
	return (0);
}

int		keys(int key, t_data *data)
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
