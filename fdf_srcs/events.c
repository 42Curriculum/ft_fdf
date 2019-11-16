/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:40:34 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/16 00:40:36 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#include "../incl/keys.h"
#include <stdio.h>

void	data_init(t_data **data)
{
	(*data)->scale = 0.5;
	(*data)->scale = 0.5;
}

int	on_key(int key, t_data **data)
{
	if (key == 53)
	{
		mlx_destroy_window((*data)->ptr, (*data)->window);
		exit(0);
	}
	return (1);
}

int mlx_prgr(t_coordinates **coords)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data_init(&data);
	data->coords = &coords;
	data->ptr = mlx_init();
	data->window = mlx_new_window(data->ptr, 500, 500, "fdf");
	mlx_key_hook(data->window, on_key, &data);
	window_init(data);
	mlx_loop(data->ptr);
	return (0);
}