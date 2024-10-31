/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:11:53 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/10 11:55:36 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

int	check_walls_or_player(t_xu8t *xu8t, int x)
{
	if (xu8t->t_m->map[x] == 8)
		errors_map(xu8t, 0);
	else if (xu8t->t_m->map[x] != 1)
		return (1);
	return (0);
}

int	check_walls_left_right(t_xu8t *xu8t)
{
	int	x;
	int	err;

	x = 0;
	err = 0;
	while (x < xu8t->t_m->max_y * xu8t->t_m->max_x)
	{
		if (check_walls_or_player(xu8t, x))
		{
			err = 1;
			xu8t->t_m->map[x] = 1;
		}
		x += xu8t->t_m->max_x;
	}
	x = xu8t->t_m->max_x - 1;
	while (x < xu8t->t_m->max_y * xu8t->t_m->max_x)
	{
		if (check_walls_or_player(xu8t, x))
		{
			err = 1;
			xu8t->t_m->map[x] = 1;
		}
		x += xu8t->t_m->max_x;
	}
	return (err);
}

int	check_walls_top_bottom(t_xu8t *xu8t)
{
	int	x;
	int	max;
	int	err;

	x = 0;
	max = xu8t->t_m->max_x;
	while (++x < max)
	{
		if (check_walls_or_player(xu8t, x))
		{
			err = 1;
			xu8t->t_m->map[x] = 1;
		}
	}
	max = (max * xu8t->t_m->max_y);
	x = max - x;
	while (++x < max)
	{
		if (check_walls_or_player(xu8t, x))
		{
			err = 1;
			xu8t->t_m->map[x] = 1;
		}
	}
	return (err);
}
