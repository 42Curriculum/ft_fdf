/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:53:55 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/16 04:43:00 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"


int main(int argc, char **argv)
{
	char **map;
	int len;
	
	len = 0;
	if (argc != 2)
		exit(write_error(2));
	map = error_loop(argv[1], &len);
	parse_file(map, len);
	exit(0);
}
