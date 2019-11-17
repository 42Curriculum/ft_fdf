/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 03:41:56 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/17 04:22:45 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#include "../incl/colors.h"
#include "../incl/keys.h"

void	selected(t_data *data)
{
	int x;
	int y;
	
	x = (*data->coords)[data->i]->n_x;
	y = (*data->coords)[data->i]->n_y;
	mlx_clear_window(data->ptr, data->window);
	window_init(data);
	mlx_pixel_put(data->ptr,data->window,x, y, GREEN);
}

void	m_view(t_data *data, int key)
{
	if (key == K_Left)
	{
		if (data->a_x < 90)
			data->a_x +=1;
	}
	else if (key == K_Right)
	{
		if (data->mode = 0)
		{
			if (data->a_x > 10)
				data->a_x -=1;
		}
	}
	else if (key == K_Up)
		data->a_z +=1;
	else if (key == K_Down)
		data->a_z -=1;
}

void	m_edit(t_data **data, int key)
{
	if (key == K_Left)
	{
		(*data)->i += 1;
		if ((*data)->i == (*data)->size)
			(*data)->i = 0;
	}
	if (key == K_Right)
	{
		(*data)->i -= 1;
		if ((*data)->i < 0)
			(*data)->i = (*data)->size - 1;
	}
	if (key == K_Down)
	{
		if ((*data)->i + (*data)->len >= (*data)->size)
			(*data)->i = ((*data)->i + (*data)->len) - (*data)->size;
		else
			(*data)->i += (*data)->len;
	}
	if (key == K_Up)
	{
		if ((*data)->i - (*data)->len < 0)
			(*data)->i = ((*data)->size - (*data)->i);
		else
			(*data)->i -= (*data)->len;
	}
}

void	mode_func(t_data **data, int key)
{
	if ((*data)->mode == 0)
		m_view(*data, key);
	else
		m_edit(data, key);
	mlx_clear_window((*data)->ptr, (*data)->window);
	window_init(*data);
}