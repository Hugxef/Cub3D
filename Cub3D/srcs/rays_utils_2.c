/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:31:16 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/07 11:27:11 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

void	horizontal_loop(t_rays *r, t_xu8t *xu8t)
{
	if (r->mp > 0 && r->mp < r->max_x * r->max_y && xu8t->t_m->map[r->mp] == 1)
	{
		r->hx = r->rx;
		r->hy = r->ry;
		r->dist_h = dist(r->px, r->py, r->rx, r->ry);
		r->dof = 32;
	}
	else
	{
		r->rx += r->xo;
		r->ry += r->yo;
		r->dof += 1;
	}
}

void	vertical_loop(t_rays *r, t_xu8t *xu8t)
{
	if (r->mp > 0 && r->mp < r->max_x * r->max_y && xu8t->t_m->map[r->mp] == 1)
	{
		r->vx = r->rx;
		r->vy = r->ry;
		r->dist_v = dist(r->px, r->py, r->vx, r->vy);
		r->dof = 32;
	}
	else
	{
		r->rx += r->xo;
		r->ry += r->yo;
		r->dof += 1;
	}
}
