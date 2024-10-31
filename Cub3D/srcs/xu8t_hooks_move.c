/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xu8t_hooks_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:59:22 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/15 15:37:39 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

void	xu8t_move_left(t_xu8t *xu8t)
{
	xu8t->t_p->pos_x += xu8t->t_p->delta_y;
	xu8t->t_p->pos_y -= xu8t->t_p->delta_x;
	mlx_clear_window(xu8t->mlx, xu8t->win);
	xu8t_render(xu8t);
}

void	xu8t_move_right(t_xu8t *xu8t)
{
	xu8t->t_p->pos_x -= xu8t->t_p->delta_y;
	xu8t->t_p->pos_y += xu8t->t_p->delta_x;
	mlx_clear_window(xu8t->mlx, xu8t->win);
	xu8t_render(xu8t);
}

void	xu8t_move_up(t_xu8t *xu8t)
{
	xu8t->t_p->pos_x += xu8t->t_p->delta_x;
	xu8t->t_p->pos_y += xu8t->t_p->delta_y;
	mlx_clear_window(xu8t->mlx, xu8t->win);
	xu8t_render(xu8t);
}

void	xu8t_move_down(t_xu8t *xu8t)
{
	xu8t->t_p->pos_x -= xu8t->t_p->delta_x;
	xu8t->t_p->pos_y -= xu8t->t_p->delta_y;
	mlx_clear_window(xu8t->mlx, xu8t->win);
	xu8t_render(xu8t);
}
