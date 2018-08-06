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

void	which_fractal(t_data *data, int q, int i)
{
	if (data->name_fract == 1)
		mandel(data, i, q);
	else if (data->name_fract == 2)
		julia(data, i, q);
	else if (data->name_fract == 5)
		san_marco(data, i, q);
	else if (data->name_fract == 4)
		siegle(data, i, q);
	else if (data->name_fract == 3)
		sierpinski(data, i, q);
}

int		make_and_put(t_data *data, int x, int y)
{
	if (data->iter == data->infinity)
	{
		data->col_imag[INDEX + 2] = 0;
		data->col_imag[INDEX + 1] = 0;
		data->col_imag[INDEX] = 0;
	}
	else
	{
		data->col_imag[INDEX + 2] = data->iter * data->color1 % 225;
		data->col_imag[INDEX] = data->iter * data->color2 % 225;
		data->col_imag[INDEX + 1] = data->iter * data->color3 % 225;
	}
	return (0);
}

void	draw(t_data *data)
{
	int	q;
	int	i;
	int	count;

	q = 0;
	count = 0;
	while (q < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
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
	if (!(data->mlx = mlx_init()))
		ft_error(2);
	if (!(data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name)))
		ft_error(2);
	if (!(data->image_ptr = mlx_new_image(data->mlx, WIDTH, HEIGHT)))
		ft_error(2);
	if (!(data->col_imag = mlx_get_data_addr(data->image_ptr,
		&data->bits_per_pixel, &data->size_line, &data->endian)))
		ft_error(2);
	data->bits_per_pixel /= 8;
}

void	for_init(t_data *data)
{
	data->min_x = -1.5;
	data->max_x = 1.0;
	data->min_y = -1.0;
	data->max_y = 1.0;
	data->infinity = 50;
	data->color1 = 1;
	data->color2 = 4;
	data->color3 = 7;
	data->zoom = 1.0f;
	data->cord1 = -0.70176;
	data->cord2 = -0.3842;
	data->mov_m = 1;
}
