/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xu8t_collisions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:12:18 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/15 11:39:41 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

int	delta_up(t_xu8t *xu8t, int mode)
{
	if (mode == 0)
		return (oriented_up_zero(xu8t));
	else
		return (oriented_up_one(xu8t));
}

int	delta_down(t_xu8t *xu8t, int mode)
{
	if (mode == 0)
		return (oriented_down_zero(xu8t));
	else
		return (oriented_down_one(xu8t));
}

int	delta_left(t_xu8t *xu8t, int mode)
{
	if (mode == 0)
		return (oriented_left_zero(xu8t));
	else
		return (oriented_left_one(xu8t));
}

int	delta_right(t_xu8t *xu8t, int mode)
{
	if (mode == 0)
		return (oriented_right_zero(xu8t));
	else
		return (oriented_right_one(xu8t));
}
