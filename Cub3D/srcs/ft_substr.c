/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:38:51 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/09 15:28:37 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i - 1);
}

char	*ft_substr(char *str, int x)
{
	int		i;
	char	*good_str;

	i = 0;
	good_str = malloc(ft_strlen(str) - x + 1);
	while (str[x] && str[x] != '\n')
	{
		good_str[i] = str[x];
		i++;
		x++;
	}
	good_str[i] = '\0';
	return (good_str);
}
