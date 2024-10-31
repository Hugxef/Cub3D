/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xu8t_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:22:50 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/14 13:11:13 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

int	sec_strjoin(char *s)
{
	int	x;

	x = ft_strlen(s);
	if (s[x] == '\n')
		return (1);
	return (0);
}

char	*xu8t_strjoin(char *s1, char *s2)
{
	char		*tab;
	long		i;
	long		e;

	i = ft_strlen(s1);
	e = ft_strlen(s2);
	tab = ft_calloc((i + e + 1) + 2, sizeof(char));
	if (!tab)
		return (NULL);
	i = -1;
	e = 0;
	while (s1[++i])
		tab[i] = s1[i];
	if (sec_strjoin(s2) == 1)
		while (s2[e] != '\n')
			tab[i++] = s2[e++];
	else
		while (s2[e])
			tab[i++] = s2[e++];
	tab[i] = '\0';
	free(s1);
	return (tab);
}
