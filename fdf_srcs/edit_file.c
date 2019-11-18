/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 03:41:56 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/17 20:10:52 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#include "../incl/colors.h"
#include "../incl/keys.h"

void	selected(t_data *data)
{
	float x;
	float y;
	
	mlx_clear_window(data->ptr, data->window);
	window_init(data);
	x = (*data->coords)[data->i]->n_x;
	y = (*data->coords)[data->i]->n_y;
	draw_square(x, y, data);
}

void	m_view(t_data *data, int key)
{
	if (key == K_Up)
	{
		if (data->a_x < 90)
			data->a_x +=1;
	}
	else if (key == K_Down)
	{
		if (data->mode == 0)
		{
			if (data->a_x > 10)
				data->a_x -=1;
		}
	}
	else if (key == K_Right)
		data->a_z +=1;
	else if (key == K_Left)
		data->a_z -=1;
}

void	m_edit(t_data **data, int key)
{
	select_LR(data, key);
	select_UD(data, key);
	move_pixel(data, key);
	selected(*data);
}

void	mode_func(t_data **data, int key)
{
	if ((*data)->mode == 0)
	{
		m_view(*data, key);
		mlx_clear_window((*data)->ptr, (*data)->window);
		window_init(*data);
	}
	else
		m_edit(data, key);
}