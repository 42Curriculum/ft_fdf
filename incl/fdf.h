/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:56:04 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/17 03:02:44 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/get_next_line.h"
# include "../libft/libft.h"

# include <stdlib.h>

typedef struct	s_coordinates
{
	float	x;
	float	y;
	float	z;
	float	n_x;
	float	n_y;
}				t_coordinates;

typedef struct s_line
{
	float x1;
	float x2;
	float y1;
	float y2;
}				t_line;

typedef struct 	s_data
{
	t_coordinates	***coords;
	float			scale;
	void			*ptr;
	void			*window;
	int				size;
	int				len;
	int 			win_len;
	int 			win_h;
	int				color;
	int				i;
	int				mode;
	int				t_Y;
	int				t_X;
	int				a_z;
	int				a_x;
}				t_data;

int mlx_prgr(t_coordinates **coords, int size, int len);

int window_init(t_data *data);
void scale(t_data **data, int UD);

int reader(char *file);
void parse_file(char **map, int len);

int	make_image(t_data *data);

int write_error(int flag);
char **error_loop(char *arg, int *len);

int edit_file(char *arg);

#endif