/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:01:25 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/17 20:55:54 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#include "../incl/colors.h"
#include "../incl/keys.h"
#include <stdio.h>

void	 move_pixel(t_data **data, int key)
{
	if (key == K_W)
		(*(*data)->coords)[(*data)->i]->z += 1;
	if (key == K_S)
		(*(*data)->coords)[(*data)->i]->z -= 1;
	if (key == K_A)
		(*(*data)->coords)[(*data)->i]->x -= 0.5;
	if (key == K_D)
		(*(*data)->coords)[(*data)->i]->x += 0.5;
}

void	 select_LR(t_data **data, int key)
{
	if (key == K_Right)
	{
		(*data)->i += 1;
		if ((*data)->i == (*data)->size)
			(*data)->i = 0;
	}
	if (key == K_Left)
	{
		(*data)->i -= 1;
		if ((*data)->i < 0)
			(*data)->i = (*data)->size - 1;
	}
}

void	 select_UD(t_data **data, int key)
{
	if (key == K_Down)
	{
		if ((*data)->i + (*data)->len < (*data)->size)
			(*data)->i += (*data)->len;
	}
	if (key == K_Up)
	{
		if (((*data)->i - (*data)->len) >= 0)
			(*data)->i -= (*data)->len;
	}
}