/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xu8t_hooks_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20.3/11/18 14:03:56 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/15 15:24:35 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

void	xu8t_camera_left(t_xu8t *xu8t)
{
	xu8t->t_p->angle -= 0.3;
	if (xu8t->t_p->angle < 0)
		xu8t->t_p->angle = 2 * M_PI;
	xu8t->t_p->delta_x = cos(xu8t->t_p->angle) * 5;
	xu8t->t_p->delta_y = sin(xu8t->t_p->angle) * 5;
	mlx_clear_window(xu8t->mlx, xu8t->win);
	xu8t_render(xu8t);
}

void	xu8t_camera_right(t_xu8t *xu8t)
{
	xu8t->t_p->angle += 0.3;
	if (xu8t->t_p->angle > 2 * M_PI)
		xu8t->t_p->angle = 0;
	xu8t->t_p->delta_x = cos(xu8t->t_p->angle) * 5;
	xu8t->t_p->delta_y = sin(xu8t->t_p->angle) * 5;
	mlx_clear_window(xu8t->mlx, xu8t->win);
	xu8t_render(xu8t);
}
