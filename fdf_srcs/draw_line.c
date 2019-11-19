/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:40:36 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/19 05:44:12 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#include "../incl/colors.h"
#include <math.h>

void	draw_square(float x, float y, t_data *data)
{
	int i;

	i = 0;
	while (i < 10)
	{
		mlx_pixel_put(data->ptr, data->window, x + i, y, GREEN);
		i++;
	}
	mlx_pixel_put(data->ptr, data->window, x + 1, y + 1, GREEN);
	mlx_pixel_put(data->ptr, data->window, x + 2, y + 2, GREEN);
	mlx_pixel_put(data->ptr, data->window, x + 3, y + 3, GREEN);
	mlx_pixel_put(data->ptr, data->window, x + 1, y - 1, GREEN);
	mlx_pixel_put(data->ptr, data->window, x + 2, y - 2, GREEN);
	mlx_pixel_put(data->ptr, data->window, x + 3, y - 3, GREEN);
}

int		set_var_v2(int (*err)[], int (*d)[], int flag)
{
	if (flag == 1)
	{
		(*err)[0] -= (*d)[1];
	}
	if (flag == 2)
	{
		(*err)[0] += (*d)[0];
	}
	return (1);
}

void	set_vars(t_line *line, int (*x)[], int (*y)[], int (*d)[])
{
	(*x)[0] = line->x1;
	(*x)[1] = line->x2;
	(*y)[0] = line->y1;
	(*y)[1] = line->y2;
	(*d)[0] = abs((*x)[1] - (*x)[0]);
	(*d)[1] = abs((*y)[1] - (*y)[0]);
}

void	draw_line(t_line *line, t_data *data)
{
	int x[2];
	int y[2];
	int d[2];
	int s[2];
	int err[2];

	set_vars(line, &x, &y, &d);
	s[0] = x[0] < x[1] ? 1 : -1;
	s[1] = y[0] < y[1] ? 1 : -1;
	err[0] = (d[0] > d[1] ? d[0] : -d[1]) / 2;
	while (1)
	{
		mlx_pixel_put(data->ptr, data->window, x[0], y[0], WHITE);
		if (x[0] == x[1] && y[0] == y[1])
			break ;
		err[1] = err[0];
		if (err[1] > -d[0] && (set_var_v2(&err, &d, 1)))
			x[0] += s[0];
		if (err[1] < d[1] && (set_var_v2(&err, &d, 2)))
			y[0] += s[1];
	}
}

int		make_image(t_data *data, int i)
{
	t_line *line;

	line = malloc(sizeof(t_line));
	while (i < data->size)
	{
		if (((i + 1) < data->size) && ((i + 1) % data->len != 0))
		{
			line->x1 = (*data->coords)[i]->n_x;
			line->y1 = (*data->coords)[i]->n_y;
			line->x2 = (*data->coords)[i + 1]->n_x;
			line->y2 = (*data->coords)[i + 1]->n_y;
			draw_line(line, data);
		}
		if ((i + data->len) < data->size)
		{
			line->x1 = (*data->coords)[i]->n_x;
			line->y1 = (*data->coords)[i]->n_y;
			line->x2 = (*data->coords)[i + data->len]->n_x;
			line->y2 = (*data->coords)[i + data->len]->n_y;
			draw_line(line, data);
		}
		i++;
	}
	free(line);
	return (0);
}
