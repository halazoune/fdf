/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 12:46:18 by ncoden            #+#    #+#             */
/*   Updated: 2015/06/14 22:12:47 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
	#include <stdio.h>

int				loop_hook(t_3denv *env)
{
	env->cam->ang.x += ft_degtorad(1);
	env->cam->ang.y += ft_degtorad(1);
	env->cam->ang.z += ft_degtorad(1);
	ft_3denvprint(env);
	return (1);
}

int				main(int argc, char **argv)
{
	int			fd;
	int			**map;
	t_3denv		*env;

	if (argc != 2)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	if (!(map = init_map(fd)))
		return (0);
	if (!(env = init_env(map)))
		return (0);
	mlx_loop_hook(env->mlx, &loop_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
