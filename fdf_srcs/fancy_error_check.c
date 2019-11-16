/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fancy_error_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 00:32:19 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/16 04:00:27 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int edit_file(char *arg)
{
    char *str;
    str = ft_strjoin("vim ", arg);
    return (system(str));
}

int         write_error(int flag)
{
    if (flag == 1)
        ft_putstr("\e[0;31m Error\n");
    if (flag == 2)
        ft_putstr("\e[0;31m Usage : fdf input_file\n");
    if (flag == 3)
        ft_putstr("\e[0;31m Error : Invalid character in file\n");
    if (flag == 4)
        ft_putstr("\e[0;31m Error : Invalid format\n");
    if (flag == 5)
        ft_putstr("\e[0;31m Error : Empty file\n");\
    if (flag > 5)
    {
        if (flag == 6)
            ft_putstr("\e[0;31m Error : File does not exist\n");
        if (flag == 7)
            ft_putstr("\e[0;31m Error : Cannot read directory\n");
        return (-1);
    }
    return (0);
}
