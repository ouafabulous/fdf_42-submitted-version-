/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:45:27 by omoudni           #+#    #+#             */
/*   Updated: 2022/03/30 17:58:59 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx_linux/mlx.h"

void	ft_rotate(int key, t_data *data)
{
	t_map	*map;

	map = data->map;
	if (key == U)
		map->rx -= 5;
	if (key == I)
		map->rx += 5;
	if (key == J)
		map->ry += 5;
	if (key == K)
		map->ry -= 5;
	if (key == N)
		map->rz += 5;
	if (key == M)
		map->rz -= 5;
}

void	reset(t_data *data)
{
	t_map	*map;

	map = data->map;
	map->iso = 1;
	init_srt(map);
	ft_scale(map, (float)(map->i), (float)(map->j));
}

int	key_hook(int key, t_data *data)
{
	t_map	*map;

	map = data->map;
	if (key == ESC)
		ft_close(data);
	free_2_reinit_map(map);
	if (key == D || key == F || key == R || key == C)
		ft_move(key, data);
	if (key == UP || key == DOWN)
		ft_zoom(key, data);
	if (key == U || key == I || key == J || key == K || key == N || key == M)
		ft_rotate(key, data);
	if (key == P)
	{
		if (map->iso)
			map->iso = 0;
		else
			map->iso = 1;
	}
	if (key == SPACE)
		reset(data);
	reinitialize_map(map);
	display(data);
	free_2_reinit_map(map);
	return (0);
}

void	free_int_point(float **p_int)
{
	free(*p_int);
	*p_int = NULL;
}
