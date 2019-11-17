/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:40:34 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/17 04:23:41 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#include "../incl/keys.h"
#include "../incl/colors.h"
#include <stdio.h>

void	data_init(t_data **data, int size, int len)
{
	(*data)->scale = 16;
	(*data)->size = size;
	(*data)->len = len;
	(*data)->win_h = ((size / len) + (size / len) / 2) * 10;
	(*data)->win_len = (len + len/2) * 16; 
	(*data)->mode = 0;
	(*data)->i = 0;
	(*data)->color = WHITE;
	(*data)->t_Y = 0;
	(*data)->t_X = 0;
	(*data)->a_x = 50;
	(*data)->a_z = 45;
}

int	on_key(int key, t_data **data)
{
	if (key == K_Esc)
	{
		mlx_destroy_window((*data)->ptr, (*data)->window);
		exit(0);
	}
	if (key == K_return)
	{
		(*data)->mode = ((*data)->mode == 0) ? 1 : 0;
		mlx_clear_window((*data)->ptr, (*data)->window);
    	window_init(*data);
	}
	return (1);
}

int on_mouse(int key, int x, int y, t_data **data)
{
	x +=0;
	y+=0;
	if (key == K_Scroll_U)
		scale(data, 0);
	if (key == K_Scroll_D)
		scale(data, 1);
	return (1);
}

int mlx_prgr(t_coordinates **coords, int size, int len)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data_init(&data, size, len);
	data->coords = &coords;
	data->ptr = mlx_init();
	data->window = mlx_new_window(data->ptr, data->win_len, data->win_h, "fdf");
	mlx_key_hook(data->window, on_key, &data);
	mlx_mouse_hook(data->window, on_mouse, &data);
	window_init(data);
	mlx_loop(data->ptr);
	return (0);
}