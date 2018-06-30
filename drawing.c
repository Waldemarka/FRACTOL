/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:23:54 by vomelchu          #+#    #+#             */
/*   Updated: 2018/06/27 15:23:55 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"
#include <stdio.h>

void 	which_fractal(t_data *data, int q, int i)
{

	if (data->name_fract == 1)
		mandel(data, i, q);
	else if (data->name_fract == 2)
		julia(data, i, q);
	else if (data->name_fract == 3)
		sierp(data, i, q);
}

void 	draw(t_data *data)
{
	int q; 
	int i;
	int count;

	q = 0;
	count = 0;
	mlx_clear_window(data->mlx, data->win);
	while(q < HEIGHT)
	{
		i = 0;
		while(i < WIDTH)
		{
			which_fractal(data, q, i);
			count = make_and_put(data, i, q);
		
			i++;
		}
		q++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image_ptr, 0, 0);	
}

void	all_open(t_data *data)
{
	if(!(data->mlx = mlx_init()))
		ft_error(2);
	if(!(data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name)))
		ft_error(2);
	if(!(data->image_ptr = mlx_new_image (data->mlx, WIDTH, HEIGHT)))
		ft_error(2);
	if(!(data->col_imag = mlx_get_data_addr(data->image_ptr, &data->bits_per_pixel,
		&data->size_line, &data->endian)))
		ft_error(2);
	data->bits_per_pixel /= 8;
}

void			for_init(t_data *data)
{
	data->min_x = -1.5f;
	data->max_x = 1.0f;
	data->min_y = -1.0f;
	data->max_y = 1.0f;
	data->infinity = 200;
	data->color1 = 10;
	data->color2 = 20;
	data->color3 = 30;
}