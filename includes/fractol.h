/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:55:05 by vomelchu          #+#    #+#             */
/*   Updated: 2018/06/24 12:55:06 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../libft/includes/libft.h"

# define HEIGHT 	1000
# define WIDTH 		1200
# define INDEX		(x * 4) + (y * WIDTH * 4)

typedef struct			s_data
{
	void		*mlx;
	void		*win;
	void		*image_ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;

	int 		color1;
	int 		color2;
	int			color3;

	float		min_x;
	float		max_x; 
	float		min_y;
	float		max_y; 
	float		infinity;
	int 		iter;

	char		*name;
	int		 	name_fract;
	char		*col_imag;
}						t_data;

int		checkname(char *str, t_data *data);
void	ft_error(int q);
void	for_name(int i, t_data *data);
void	for_argv();
void	all_open(t_data *data);
int		mandel(t_data *data, int x, int y);
int 	make_and_put(t_data *data, int x, int y);
void	for_init(t_data *data);
void 	draw(t_data *data);
int		julia(t_data *data, int x, int y);
int		sierp(t_data *data, int x, int y);

#endif
