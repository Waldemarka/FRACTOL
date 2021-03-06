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

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../libft/includes/libft.h"

# define HEIGHT 	600
# define WIDTH 		800
# define LD			long double
# define WIDTX		(data->max_x - data->min_x)
# define HEIGY		(data->max_y - data->min_y)
# define INDEX		(x * 4) + (y * WIDTH * 4)
# define MOTION_MASK (1L<<6)
# define MOTION_NOTIFY	6

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*image_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				color1;
	int				color2;
	int				color3;
	int				str;
	long double		min_x;
	long double		max_x;
	long double		min_y;
	long double		max_y;
	long double		zoom;
	long double		cord1;
	long double		cord2;
	int				mov_m;
	float			infinity;
	int				iter;
	char			*name;
	int				name_fract;
	char			*col_imag;
}					t_data;

int					checkname(char *str, t_data *data);
void				ft_error(int q);
void				for_name(int i, t_data *data);
void				for_argv();
void				all_open(t_data *data);
int					mandel(t_data *data, int x, int y);
int					make_and_put(t_data *data, int x, int y);
void				for_init(t_data *data);
void				draw(t_data *data);
int					julia(t_data *data, int x, int y);
int					zoom(int key, int x, int y, t_data *data);
int					exit_x(void);
int					keys(int key, t_data *data);
int					siegle(t_data *data, int x, int y);
LD					coord(LD x, LD widt, LD min, LD max);
int					sierpinski(t_data *data, int x, int y);
int					san_marco(t_data *data, int x, int y);
int					moving_mod(int x, int y, t_data *data);

#endif
