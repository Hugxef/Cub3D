/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:53:19 by hugrene           #+#    #+#             */
/*   Updated: 2022/03/24 11:53:21 by hugrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*str;
	int		nbr;

	buffer = ft_calloc(((BUFFER_SIZE / BUFFER_SIZE) + 1), sizeof(char));
	str = NULL;
	nbr = read(fd, buffer, (BUFFER_SIZE / BUFFER_SIZE));
	if (nbr > 0)
		str = ft_calloc(((BUFFER_SIZE / BUFFER_SIZE) + 1), sizeof(char));
	while (nbr > 0 && buffer[0] != '\n')
	{
		str = ft_strjoin(str, buffer);
		nbr = read(fd, buffer, (BUFFER_SIZE / BUFFER_SIZE));
	}
	if (buffer[0] == '\n')
		str = ft_strjoin(str, "\n");
	free(buffer);
	return (str);
}
