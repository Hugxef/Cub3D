/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:43:37 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/14 13:37:32 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

int	get_player_position_x(t_xu8t *xu8t)
{
	int	tile;
	int	pos_x;

	tile = xu8t->t_m->tile;
	pos_x = xu8t->t_p->pos_x;
	return (tile * pos_x + (tile / 2));
}

int	get_player_position_y(t_xu8t *xu8t)
{
	int	tile;
	int	pos_y;

	tile = xu8t->t_m->tile;
	pos_y = xu8t->t_p->pos_y;
	return (tile * pos_y + (tile / 2));
}

void	get_player_orientation(t_xu8t *xu8t, char o)
{
	if (o == 'N')
		xu8t->t_p->angle = xu8t->npi;
	else if (o == 'S')
		xu8t->t_p->angle = xu8t->spi;
	else if (o == 'E')
		xu8t->t_p->angle = xu8t->epi;
	else
		xu8t->t_p->angle = xu8t->wpi;
}

void	create_xpm_images(t_xu8t *xu8t)
{
	xu8t->nx->img = mlx_xpm_file_to_image(xu8t->mlx, xu8t->nx->path,
			&xu8t->nx->x_width, &xu8t->nx->x_height);
	xu8t->nx->data = mlx_get_data_addr(xu8t->nx->img, &xu8t->nx->bpp,
			&xu8t->nx->size_l, &xu8t->nx->endian);
	xu8t->sx->img = mlx_xpm_file_to_image(xu8t->mlx, xu8t->sx->path,
			&xu8t->sx->x_width, &xu8t->sx->x_height);
	xu8t->sx->data = mlx_get_data_addr(xu8t->sx->img, &xu8t->sx->bpp,
			&xu8t->sx->size_l, &xu8t->sx->endian);
	xu8t->ex->img = mlx_xpm_file_to_image(xu8t->mlx, xu8t->ex->path,
			&xu8t->ex->x_width, &xu8t->ex->x_height);
	xu8t->ex->data = mlx_get_data_addr(xu8t->ex->img, &xu8t->ex->bpp,
			&xu8t->ex->size_l, &xu8t->ex->endian);
	xu8t->wx->img = mlx_xpm_file_to_image(xu8t->mlx, xu8t->wx->path,
			&xu8t->wx->x_width, &xu8t->wx->x_height);
	xu8t->wx->data = mlx_get_data_addr(xu8t->wx->img, &xu8t->wx->bpp,
			&xu8t->wx->size_l, &xu8t->wx->endian);
}

t_xu8t	*create_xu8t(void)
{
	t_xu8t	*xu8t;

	xu8t = ft_calloc(1, sizeof(t_xu8t));
	xu8t->res_x = 640;
	xu8t->res_y = 400;
	xu8t->t_p = ft_calloc(1, sizeof(t_player));
	xu8t->t_p->angle = 11451464;
	xu8t->t_m = ft_calloc(1, sizeof(t_map));
	xu8t->t_m->tile = 64;
	xu8t->t_m->max_x = 11451464;
	xu8t->t_m->max_y = 0;
	xu8t->t_m->mal = 0;
	xu8t->nx = ft_calloc(1, sizeof(t_xpm));
	xu8t->sx = ft_calloc(1, sizeof(t_xpm));
	xu8t->ex = ft_calloc(1, sizeof(t_xpm));
	xu8t->wx = ft_calloc(1, sizeof(t_xpm));
	xu8t->wpi = 1 * M_PI;
	xu8t->spi = 1 * M_PI_2;
	xu8t->npi = 3 * M_PI_2;
	xu8t->epi = 2 * M_PI;
	xu8t->mlx = mlx_init();
	xu8t->win = mlx_new_window(xu8t->mlx, xu8t->res_x, xu8t->res_y, "Cub3D");
	xu8t->img = mlx_new_image(xu8t->mlx, xu8t->res_x, xu8t->res_y);
	return (xu8t);
}
