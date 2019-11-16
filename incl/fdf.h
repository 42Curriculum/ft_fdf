/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:56:04 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/16 03:43:10 by jjosephi         ###   ########.fr       */
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
}				t_data;

int mlx_prgr(t_coordinates **coords);

int window_init(t_data *data);
void scale(t_data *data);

int reader(char *file);
//int parse_file( char *arg);

int	make_image(t_data *data);

int write_error(int flag);
int file_check(char *arg, char ***map);
int error_loop(char *arg);

int edit_file(char *arg);

#endif