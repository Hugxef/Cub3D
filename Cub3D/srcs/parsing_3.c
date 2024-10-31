/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:02:46 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/15 16:55:53 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

int	get_player_position(t_xu8t *xu8t, int i)
{
	{
		if (xu8t->t_p->angle != 11451464)
			errors_map(xu8t, 3);
		get_player_orientation(xu8t, xu8t->t_m->map_str[i]);
		xu8t->t_m->map[i] = 8;
	}
	return (i);
}

void	str_to_int_loop(t_xu8t *xu8t, int i)
{
	if (xu8t->t_m->map_str[i] == 'N' || xu8t->t_m->map_str[i] == 'S'
		|| xu8t->t_m->map_str[i] == 'E' || xu8t->t_m->map_str[i] == 'W')
		xu8t->p_pos = get_player_position(xu8t, i);
	else if (xu8t->t_m->map_str[i] == ' ')
		xu8t->t_m->map[i] = 1;
	else if (xu8t->t_m->map_str[i] == '0')
		xu8t->t_m->map[i] = 0;
	else if (xu8t->t_m->map_str[i] == '1')
		xu8t->t_m->map[i] = 1;
	else
		errors_map(xu8t, 1);
}

int	check_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	map_struct(t_xu8t *xu8t)
{
	xu8t->t_m = ft_calloc(1, sizeof(t_map));
	xu8t->t_m->tile = 64;
	xu8t->t_m->max_x = 11451464;
	xu8t->t_m->max_y = 0;
	xu8t->t_m->mal = 0;
}
