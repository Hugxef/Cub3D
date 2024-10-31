/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:50:51 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/07 11:26:55 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

void	reset_casting_values(t_rays *r, int mode)
{
	r->dof = 0;
	if (mode == 0)
	{
		r->dist_h = 11451464;
		r->hx = r->px;
		r->hy = r->py;
		r->a_tan = -1 / tan(r->ra);
	}
	else
	{
		r->dist_v = 11451464;
		r->vx = r->px;
		r->vy = r->py;
		r->a_tan = -tan(r->ra);
	}
}

void	horizontal_casting(t_rays *r)
{
	reset_casting_values(r, 0);
	if (r->ra > M_PI)
	{
		r->ry = (((int)r->py >> 6) << 6) - 0.0001;
		r->rx = (r->py - r->ry) * r->a_tan + r->px;
		r->yo = -64;
		r->xo = -r->yo * r->a_tan;
	}
	if (r->ra < M_PI)
	{
		r->ry = (((int)r->py >> 6) << 6) + 64;
		r->rx = (r->py - r->ry) * r->a_tan + r->px;
		r->yo = 64;
		r->xo = -r->yo * r->a_tan;
	}
	if (r->ra == 0 || r->ra == (int)M_PI)
	{
		r->rx = r->px;
		r->ry = r->py;
		r->dof = 32;
	}
}

void	vertical_casting(t_rays *r)
{
	reset_casting_values(r, 1);
	if (r->ra > M_PI_2 && r->ra < 3 * M_PI_2)
	{
		r->rx = (((int)r->px >> 6) << 6) - 0.0001;
		r->ry = (r->px - r->rx) * r->a_tan + r->py;
		r->xo = -64;
		r->yo = -r->xo * r->a_tan;
	}
	if (r->ra < M_PI_2 || r->ra > 3 * M_PI_2)
	{
		r->rx = (((int)r->px >> 6) << 6) + 64;
		r->ry = (r->px - r->rx) * r->a_tan + r->py;
		r->xo = 64;
		r->yo = -r->xo * r->a_tan;
	}
	if (r->ra == 0 || r->ra == (int)M_PI)
	{
		r->rx = r->px;
		r->ry = r->py;
		r->dof = 32;
	}
}

void	rays_angle_calc(t_rays *r, double angle, int mode)
{
	if (mode == 0)
		r->ra = angle - DR * (r->fov / 2);
	else
		r->ra += DR / r->rays_coef;
	if (r->ra < 0)
		r->ra += 2 * M_PI;
	if (r->ra > 2 * M_PI)
		r->ra -= 2 * M_PI;
}

void	rays_init(t_xu8t *xu8t, t_rays *r)
{
	r->fov = 45;
	r->rays_coef = 20;
	r->loop_offset = xu8t->res_x / (r->fov * r->rays_coef);
	r->max_x = xu8t->t_m->max_x;
	r->max_y = xu8t->t_m->max_y;
	r->dist_h = 11451464;
	r->dist_v = 11451464;
	r->hx = xu8t->t_p->pos_x;
	r->hy = xu8t->t_p->pos_y;
	r->vx = xu8t->t_p->pos_x;
	r->vy = xu8t->t_p->pos_y;
	r->px = xu8t->t_p->pos_x;
	r->py = xu8t->t_p->pos_y;
	r->i0 = malloc (sizeof(int) * 2);
	r->i1 = malloc (sizeof(int) * 2);
}
