/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xu8t_collisions_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:11:48 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/15 15:23:23 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

int	oriented_left_zero(t_xu8t *xu8t)
{
	double	x;
	double	y;

	x = xu8t->t_p->pos_x + xu8t->t_p->delta_y;
	x /= 64;
	y = xu8t->t_p->pos_y / 64;
	if (xu8t->t_p->angle < xu8t->epi && xu8t->t_p->angle > xu8t->wpi)
		x -= 0.75;
	else
		x += 0.75;
	if (xu8t->t_m->ddmap[(int)y][(int)x] == 0)
		return (1);
	else
		return (0);
}

int	oriented_left_one(t_xu8t *xu8t)
{
	double	x;
	double	y;

	y = xu8t->t_p->pos_y - xu8t->t_p->delta_x;
	y /= 64;
	x = xu8t->t_p->pos_x / 64;
	if (xu8t->t_p->angle < xu8t->npi && xu8t->t_p->angle > xu8t->spi)
		y += 0.75;
	else
		y -= 0.75;
	if (xu8t->t_m->ddmap[(int)y][(int)x] == 0)
		return (1);
	else
		return (0);
}

int	oriented_right_zero(t_xu8t *xu8t)
{
	double	x;
	double	y;

	x = xu8t->t_p->pos_x - xu8t->t_p->delta_y;
	x /= 64;
	y = xu8t->t_p->pos_y / 64;
	if (xu8t->t_p->angle < xu8t->epi && xu8t->t_p->angle > xu8t->wpi)
		x += 0.75;
	else
		x -= 0.75;
	if (xu8t->t_m->ddmap[(int)y][(int)x] == 0)
		return (1);
	else
		return (0);
}

int	oriented_right_one(t_xu8t *xu8t)
{
	double	x;
	double	y;

	y = xu8t->t_p->pos_y + xu8t->t_p->delta_x;
	y /= 64;
	x = xu8t->t_p->pos_x / 64;
	if (xu8t->t_p->angle < xu8t->npi && xu8t->t_p->angle > xu8t->spi)
		y -= 0.75;
	else
		y += 0.75;
	if (xu8t->t_m->ddmap[(int)y][(int)x] == 0)
		return (1);
	else
		return (0);
}
