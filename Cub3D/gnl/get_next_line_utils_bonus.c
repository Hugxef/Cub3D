/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:55:48 by hugrene           #+#    #+#             */
/*   Updated: 2022/03/24 11:57:18 by hugrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*tab;
	int		x;

	x = -1;
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
	int		i1;

	i = 0;
	i1 = 0;
	while (s1[i])
		i++;
	while (s2[i1])
		i1++;
	tab = malloc(sizeof(char) * (i + i1 + 1));
	if (!tab)
		return (NULL);
	i = -1;
	i1 = 0;
	while (s1[++i])
		tab[i] = s1[i];
	while (s2[i1])
		tab[i++] = s2[i1++];
	tab[i] = '\0';
	free(s1);
	return (tab);
}
