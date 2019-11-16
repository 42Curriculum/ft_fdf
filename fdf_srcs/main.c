/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:53:55 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/16 03:40:46 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"


int main(int argc, char **argv)
{
	//char **map;
	if (argc != 2)
		exit(write_error(2));
	error_loop(argv[1]);
	//parse_file(map);
	exit(0);
}
