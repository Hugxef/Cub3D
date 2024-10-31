/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:18:25 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/15 15:51:58 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

int	souris(t_xu8t *xu8t)
{
	free_moi_connard(xu8t);
	exit(0);
}

void	free_moi_connard(t_xu8t *xu8t)
{
	if (xu8t->t_m->map_str)
		free(xu8t->t_m->map_str);
	if (xu8t->t_m->map)
		free(xu8t->t_m->map);
	if (xu8t->t_m)
		free(xu8t->t_m);
	if (xu8t->t_p)
		free(xu8t->t_p);
	if (xu8t)
		free(xu8t);
}

void	errors_map(t_xu8t *xu8t, int err)
{
	if (err == 0)
		printf("[XU8T] Joueur placé sur mur extérieur\n");
	else if (err == 1)
		printf("[XU8T] Caractère invalide dans la map\n");
	else if (err == 2)
		printf("[XU8T] Couleurs invalides\n");
	else if (err == 3)
		printf("[XU8T] Erreur de position du joueur\n");
	else if (err == 4)
		printf("[XU8T] Erreur de texture\n");
	else if (err == 5)
		printf("[XU8T] Problème avec le fichier map\n");
	else if (err == 6)
		printf("[XU8T] Problème avec les couleurs\n");
	free_moi_connard(xu8t);
	exit(5);
}

void	errors_malloc(t_xu8t *xu8t)
{
	printf("[XU8T] Problème de malloc\n");
	free_moi_connard(xu8t);
	exit(6);
}

void	errors_open(t_xu8t *xu8t, int err)
{
	if (err == 0)
		printf("[XU8T] La texture n'est pas un xpm\n");
	if (err == 1)
		printf("[XU8T] La texture n'existe pas\n");
	if (err == 3)
		printf("[XU8T] La map n'a pas la bonne extension\n");
	free_moi_connard(xu8t);
	exit(7);
}
