/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:56:04 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/19 05:45:28 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/get_next_line.h"
# include "../libft/libft.h"

# include <stdlib.h>

typedef struct		s_coordinates
{
	int				x;
	int				y;
	int				z;
	float			n_x;
	float			n_y;
}					t_coordinates;

typedef struct		s_line
{
	float			x1;
	float			x2;
	float			y1;
	float			y2;
}					t_line;

typedef struct		s_data
{
	t_coordinates	***coords;
	float			scale;
	void			*ptr;
	void			*window;
	int				size;
	int				len;
	int				win_len;
	int				win_h;
	int				i;
	int				mode;
	int				a_z;
	int				a_x;
}					t_data;

int					mlx_prgr(t_coordinates **coords, int size, int len);

void				window_init(t_data *data);
void				scale(t_data **data, int ud);
void				draw_square(float x, float y, t_data *data);

int					reader(char *file);
void				parse_file(char **map, int len);

int					make_image(t_data *data, int i);

int					write_error(int flag);
char				**error_loop(char *arg, int *len);

int					edit_file(char *arg);

void				mode_func(t_data **data, int key);

void				move_pixel(t_data **data, int key);
void				select_lr(t_data **data, int key);
void				select_ud(t_data **data, int key);

void				create_file(t_data *data);
void				free_n_exit(t_data *data);

#endif
