/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_better_strjoin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 01:34:50 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/16 02:03:06 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_better_strjoin(char **str1, char *str2)
{
	char *new;
	char *temp;

	temp = *str1;
	new = ft_strjoin(*str1, str2);
	free(temp);
	return (new);
}
