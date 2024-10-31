/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:30:43 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/15 09:30:15 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"
#include <sys/fcntl.h>

void	make_twod_map(t_xu8t *cub)
{
	int	x;
	int	j;
	int	z;

	x = 0;
	z = 0;
	cub->t_m->ddmap = malloc(sizeof(int *) * cub->t_m->max_y + 1);
	while (x < cub->t_m->max_y)
		cub->t_m->ddmap[x++] = malloc(sizeof(int) * cub->t_m->max_x + 1);
	x = 0;
	while (x < cub->t_m->max_y)
	{
		j = 0;
		while (j < cub->t_m->max_x)
		{
			if (cub->t_m->map[z] == 8)
				cub->t_m->ddmap[x][j] = 0;
			else
				cub->t_m->ddmap[x][j] = cub->t_m->map[z];
			j++;
			z++;
		}
		x++;
	}
}

void	ugly_textures_loading(t_xu8t *cub)
{
	create_xpm_images(cub);
	create_xpm_images(cub);
	create_xpm_images(cub);
	create_xpm_images(cub);
}

int	key_hook(int key, t_xu8t *cub)
{
	if (key == 53)
	{
		mlx_destroy_image(cub->mlx, cub->img);
		mlx_clear_window(cub->mlx, cub->win);
		mlx_destroy_window(cub->mlx, cub->win);
		exit(0);
	}
	if (key == 13)
		xu8t_move_up(cub);
	if (key == 1)
		xu8t_move_down(cub);
	if (key == 0)
		xu8t_move_left(cub);
	if (key == 2)
		xu8t_move_right(cub);
	if (key == 123)
		xu8t_camera_left(cub);
	if (key == 124)
		xu8t_camera_right(cub);
	return (0);
}

int	main(int argc, char **argv)
{
	t_xu8t	*cub;

	if (argc != 2)
		return (1);
	cub = create_xu8t();
	if (!check_extension(argv[1], "cub"))
		errors_open(cub, 3);
	cub->file = open(argv[1], O_RDONLY);
	if (cub->file == -1)
		return (2);
	cub->file_bis = open(argv[1], O_RDONLY);
	get_map_data(cub);
	if (cub->t_p->angle == 11451464)
		errors_map(cub, 3);
	ugly_textures_loading(cub);
	cub->t_p->pos_x = get_player_position_x(cub);
	cub->t_p->pos_y = get_player_position_y(cub);
	cub->t_p->delta_x = cos(cub->t_p->angle) * 5;
	cub->t_p->delta_y = sin(cub->t_p->angle) * 5;
	mlx_key_hook(cub->win, key_hook, cub);
	mlx_hook(cub->win, 17, 0, souris, cub);
	xu8t_render(cub);
	mlx_loop(cub->mlx);
	free_moi_connard(cub);
	return (0);
}
