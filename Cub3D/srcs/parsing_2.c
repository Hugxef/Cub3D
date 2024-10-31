/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:37:01 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/14 12:50:06 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

void	map_str_to_int(t_xu8t *xu8t)
{
	int	i;
	int	mx;
	int	my;

	i = 0;
	mx = xu8t->t_m->max_x;
	my = xu8t->t_m->max_y;
	xu8t->t_m->map = malloc(sizeof(int) * (my * mx));
	if (!xu8t->t_m->map)
		errors_malloc(xu8t);
	while (xu8t->t_m->map_str[i])
	{
		str_to_int_loop(xu8t, i);
		i++;
	}
	xu8t->t_p->pos_x = xu8t->p_pos % xu8t->t_m->max_x;
	xu8t->t_p->pos_y = xu8t->p_pos / xu8t->t_m->max_x;
}

void	check_map(t_xu8t *xu8t, char *line)
{
	int	line_lenght;

	xu8t->t_m->max_y++;
	line_lenght = ft_strlen(line) - xu8t->t_m->max_x;
	if (line_lenght < 0)
		line_lenght = -line_lenght;
	if (xu8t->t_m->mal == 0)
	{
		xu8t->t_m->map_str = ft_strdup(line);
		xu8t->t_m->mal = 1;
	}
	else
		xu8t->t_m->map_str = xu8t_strjoin(xu8t->t_m->map_str, line);
	while (line_lenght > 0)
	{
		xu8t->t_m->map_str = xu8t_strjoin(xu8t->t_m->map_str, "1");
		line_lenght--;
	}
}

int	check_extension(char *str, char *ext)
{
	int	i;

	i = ft_strlen(str);
	if (ext[0] == 'c')
		i++;
	if (str[i - 1] != ext[2])
		return (0);
	if (str[i - 2] != ext[1])
		return (0);
	if (str[i - 3] != ext[0])
		return (0);
	if (str[i - 4] != '.')
		return (0);
	else
		return (1);
}

void	check_texture_open(t_xu8t *xu8t, char *line, t_xpm *texture)
{
	if (!check_extension(line, "xpm"))
		errors_open(xu8t, 0);
	if (open(ft_substr(line, 3), O_RDONLY) == -1)
		errors_open(xu8t, 1);
	else
		texture->path = ft_substr(line, 3);
}

void	check_texture(t_xu8t *xu8t, char *line)
{
	if (line[2] != ' ')
		errors_open(xu8t, 1);
	if (line[0] == 'N' && line[1] == 'O')
		check_texture_open(xu8t, line, xu8t->nx);
	else if (line[0] == 'S' && line[1] == 'O')
		check_texture_open(xu8t, line, xu8t->sx);
	else if (line[0] == 'E' && line[1] == 'A')
		check_texture_open(xu8t, line, xu8t->ex);
	else if (line[0] == 'W' && line[1] == 'E')
		check_texture_open(xu8t, line, xu8t->wx);
	else
		errors_map(xu8t, 4);
}
