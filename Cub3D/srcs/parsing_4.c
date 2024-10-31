/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:08:40 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/15 16:39:05 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

void	check_color(t_xu8t *xu8t, char *line)
{
	char	*transition;
	char	**spliting;

	if (line[0] == 'F')
	{
		transition = ft_substr(line, 2);
		spliting = ft_split(transition, ',');
		if (check_split(spliting) != 3)
			errors_map(xu8t, 6);
		xu8t->t_m->f_r = ft_atoi(spliting[0]);
		xu8t->t_m->f_g = ft_atoi(spliting[1]);
		xu8t->t_m->f_b = ft_atoi(spliting[2]);
	}
	else if (line[0] == 'C')
	{
		transition = ft_substr(line, 2);
		spliting = ft_split(transition, ',');
		if (check_split(spliting) != 3)
			errors_map(xu8t, 6);
		xu8t->t_m->c_r = ft_atoi(spliting[0]);
		xu8t->t_m->c_g = ft_atoi(spliting[1]);
		xu8t->t_m->c_b = ft_atoi(spliting[2]);
	}
	else
		errors_map(xu8t, 2);
}

void	check_max_map_len(t_xu8t *xu8t, char *line)
{
	int	line_lenght;

	xu8t->t_m->max_x = 0;
	while (line)
	{
		line_lenght = ft_strlen(line);
		if (line_lenght > xu8t->t_m->max_x)
			xu8t->t_m->max_x = line_lenght;
		line = get_next_line(xu8t->file_bis);
	}
}

void	select_parser(t_xu8t *xu8t, char *line, char *lenght_tester)
{
	if (ft_isletter(line[0]))
	{
		if (ft_isletter(line[1]))
			check_texture(xu8t, line);
		else if (line[1] == ' ')
			check_color(xu8t, line);
	}
	else if (ft_ismapping(line[0]))
	{
		if (xu8t->t_m->max_x == 11451464)
			check_max_map_len(xu8t, lenght_tester);
		check_map(xu8t, line);
	}
}

void	check_walls(t_xu8t *xu8t)
{
	int	err;

	err = check_walls_top_bottom(xu8t);
	err = check_walls_left_right(xu8t);
	if (err)
		printf("[XU8T] Erreur dans la map. Correction appliquée\n");
}

void	get_map_data(t_xu8t *xu8t)
{
	char	*line;
	char	*lenght_tester;

	line = get_next_line(xu8t->file);
	lenght_tester = get_next_line(xu8t->file_bis);
	while (line)
	{
		select_parser(xu8t, line, lenght_tester);
		if (!line)
			free(line);
		line = get_next_line(xu8t->file);
		if (xu8t->t_m->max_x == 11451464)
		{
			free(lenght_tester);
			lenght_tester = get_next_line(xu8t->file_bis);
		}
	}
	if (xu8t->t_m->max_x == 11451464)
		errors_map(xu8t, 5);
	map_str_to_int(xu8t);
	make_twod_map(xu8t);
	check_walls(xu8t);
}
