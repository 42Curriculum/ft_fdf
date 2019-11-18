/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:31:27 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/17 22:45:31 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "../incl/fdf.h"
#include <stdlib.h>

int error_check(char **file)
{
	int i;
	int n;

	i = 0;
	while (file[i])
	{
		n = 0;
		while (file[i][n])
		{
			if (!(ft_isdigit(file[i][n])) && n > 0)
				return (write_error(3));
            if (n == 0 && file[i][n] != '-' && !(ft_isdigit(file[i][n])))
                return (write_error(3));
			n++;
		}
		i++;
	}
	return (1);
}

int reader(char *file)
{
	int fd;

	fd = open(file, O_RDONLY | O_DIRECTORY);
	if (fd >= 0)
		return (write_error(7));
	close (fd);
	fd = open(file, O_RDONLY);
	close (fd);
	if (fd <= 0)
		return (write_error(6));
	return (1);
}

char *read_file(char *arg, int *len)
{
    char *line;
    char *str;
    int fd;

    fd = open(arg, O_RDONLY);
    str = ft_strnew(0);
    line = ft_strnew(0);
    get_next_line(fd, &line);
    if (((*len = ft_ctwords(line, ' ')) == 0) && !write_error(5))
        return(NULL);
    str = ft_better_strjoin(&str, line);
    str = ft_better_strjoin(&str, " ");
    while (get_next_line(fd, &line))
    {
        if (ft_ctwords(line, ' ') != *len && !write_error(4))
            return (NULL);
        str = ft_better_strjoin(&str, line);
        str = ft_better_strjoin(&str, " ");
        free(line);
    }
    return (str);
}

int file_check(char *arg, char ***map, int *len)
{
    char *file;

    if ((reader(arg) <= 0))
        return (-1);
    if (!(file = read_file(arg, len)))
        return (0);
    *map = ft_strsplit(file, ' ');
    free (file);
    if (!(error_check(*map)))
        return (0);
    return (1); 
}

char **error_loop(char *arg, int *len)
{
    char **map;
    int error_code;
    int b;
    char *input;
    
    input = malloc(210);
    input = ft_strcat(input, arg);
    while (((error_code = file_check(input, &map, len)) <= 0))
    {
        ft_putstr("\e[0;32m Please input a new file or type !edit \n");
        b = read(0, input, 209);
        input[b - 1] = '\0';
        if (!(ft_strcmp("!edit", input)))
        {
            if (error_code == -1)
                ft_putstr("\e[0;32m Directories and inexistant files cannot be edited \n");
            else
            {
                edit_file(arg);
                input = arg;
            }
        }
    }
    return (map);
}
