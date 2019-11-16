/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:40:39 by jjosephi          #+#    #+#             */ 
/*   Updated: 2019/11/11 17:23:41 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#include <math.h>
#include "../incl/colors.h"
#include <stdio.h>

static void rotate_x(t_coordinates *pt, float angle, float (*coord_2D)[])
{  
    angle = (angle) * (M_PI/180);
   	(*coord_2D)[1] = cos(angle) * (pt->y);
}

static void rotate_y(t_coordinates *pt, float angle, float (*coord_2D)[])
{
   	angle = (angle) * (M_PI/180);
	(*coord_2D)[0] = cos(angle) * (pt->x);
}

static void rotate_z(t_coordinates *pt, float angle, float (*coord_2D)[])
{
	angle = (angle) * (M_PI/180);
	(*coord_2D)[0] = cos(angle) * pt->x - sin(angle) * pt->y;
    (*coord_2D)[1] = sin(angle) * pt->x + cos(angle) * pt->y;
}

int window_init(t_data *data)
{
    int     i;
    float   _2d[2];

    
    i = 0;
    printf("\n Scale = %f", data->scale);
    while (i < data->size)
    {
        rotate_z((*data->coords)[i],35, &_2d);
        (*data->coords)[i]->x = _2d[0];
        (*data->coords)[i]->y = _2d[1];
        rotate_x((*data->coords)[i],45, &_2d);
        rotate_y((*data->coords)[i],25, &_2d);
        (*data->coords)[i]->x = 250 - (_2d[0] * data->scale);
        (*data->coords)[i]->y = 250 - (_2d[1] * data->scale) - (*data->coords)[i]->z;
        i++;
    }
    make_image(data);
    return (1);
}

void scale(t_data **data)
{
    (*data)->scale += 1;
    mlx_clear_window((*data)->ptr, (*data)->window);
    window_init(*data);
}