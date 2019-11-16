/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:40:34 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/16 12:09:59 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#include "../incl/keys.h"
#include <stdio.h>

void	data_init(t_data **data, int size, int len)
{
	(*data)->scale = 7;
	(*data)->size = size;
	(*data)->len = len;
}

int	on_key(int key, t_data **data)
{
	if (key == K_Esc)
	{
		mlx_destroy_window((*data)->ptr, (*data)->window);
		exit(0);
	}
	return (1);
}

int on_mouse(int key, int x, int y, t_data **data)
{
	x +=0;
	y+=0;
	if (key == K_Scroll)
		scale(data);
	return (1);
}

int mlx_prgr(t_coordinates **coords, int size, int len)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data_init(&data, size, len);
	data->coords = &coords;
	data->ptr = mlx_init();
	data->window = mlx_new_window(data->ptr, 500, 500, "fdf");
	mlx_key_hook(data->window, on_key, &data);
	mlx_mouse_hook(data->window, on_mouse, &data);
	window_init(data);
	mlx_loop(data->ptr);
	return (0);
}