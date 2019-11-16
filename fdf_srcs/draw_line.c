/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:40:36 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/14 20:11:44 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#include "../incl/colors.h"
#include <math.h>
#include <stdio.h>

//mlx_pixel_put(data->ptr, data->window, line->x2, line->y2, WHITE);

void draw_line(t_line *line, t_data *data)
{
    int x0 = line->x1;
    int y0= line->y1;
	int x1 = line->x2;
    int y1= line->y2;

   int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2, e2;
    for(;;) {
           mlx_pixel_put(data->ptr, data->window, x0, y0, WHITE);
            if (x0 == x1 && y0 == y1) break;
            e2 = err;
            if (e2 > -dx) { err -= dy; x0 += sx; }
            if (e2 < dy) { err += dx; y0 += sy; }
        }
}
	
	

int		make_image(t_data *data)
{
	int i;
	t_line *line;

	i = data->size - 1;
	line = malloc(sizeof(t_line));
	while (i >= 0)
	{
		if (((i - 1) >= 0) && i != 3 && i != 6)
		{
			line->x1 = (*data->coords)[i]->x;
			line->y1 = (*data->coords)[i]->y;
			line->x2 = (*data->coords)[i - 1]->x;
			line->y2 = (*data->coords)[i - 1]->y;
			draw_line(line, data);

		}
		if ((i - data->len) >= 0)
		{
			line->x1 = (*data->coords)[i]->x;
			line->y1 = (*data->coords)[i]->y;
			line->x2 = (*data->coords)[i - data->len]->x;
			line->y2 = (*data->coords)[i - data->len]->y;
			draw_line(line, data);
		}
		i--;
	}
	return (0);
}