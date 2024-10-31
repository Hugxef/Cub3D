/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:55:29 by hugrene           #+#    #+#             */
/*   Updated: 2023/02/06 12:40:58 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*tab;

	tab = (char *)malloc(count * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, count * size);
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		e;

	i = 0;
	e = 0;
	while (s1[i])
		i++;
	while (s2[e])
		e++;
	tab = malloc(sizeof(char) * (i + e + 1));
	if (!tab)
		return (NULL);
	i = -1;
	e = 0;
	while (s1[++i])
		tab[i] = s1[i];
	while (s2[e])
		tab[i++] = s2[e++];
	tab[i] = '\0';
	free(s1);
	return (tab);
}
