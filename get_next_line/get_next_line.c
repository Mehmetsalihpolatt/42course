/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmetpo <mehmetpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:31:33 by mehmetpo          #+#    #+#             */
/*   Updated: 2023/11/17 18:39:44 by mehmetpo         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *str, int fd)
{
	char	*line;
	int		line_i;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	line_i = 1;
	while (ft_strchr(str, '\n') == 0 && line_i != 0)
	{
		line_i = read(fd, line, BUFFER_SIZE);
		if (line_i == -1)
		{
			free(str);
			free(line);
			return (0);
		}
		line[line_i] = '\0';
		str = ft_strjoin(str, line);
	}
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = read_line(str, fd);
	if (!str)
		return (NULL);
	line = read_first_line(str);
	str = next_read(str);
	return (line);
}
