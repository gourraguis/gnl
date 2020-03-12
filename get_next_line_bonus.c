/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agourrag <agourrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:29:40 by agourrag          #+#    #+#             */
/*   Updated: 2020/03/12 01:09:57 by agourrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	free_helper(char **p1, int res)
{
	if (*p1)
	{
		free(*p1);
		*p1 = NULL;
	}
	return (res);
}

int	copy_line(char **buffer, char *eol, char **line)
{
	if (eol)
	{
		if (!(*line = malloc(eol - *buffer + 1)))
			return (free_helper(buffer, -1));
		ft_strlcpy(*line, *buffer, eol - *buffer + 1);
		ft_strlcpy(*buffer, eol + 1, ft_strlen(*buffer) + 1);
		return (1);
	}
	*line = *buffer ? ft_strdup(*buffer) : ft_strdup("");
	return (free_helper(buffer, 0));
}

int	get_next_line(int fd, char **line)
{
	static char *buffers[10240 + 1];
	char		*eol;
	char		input[BUFFER_SIZE + 1];
	char		*tmp;
	int			size;

	if (fd < 0 || fd > 10240 || !line)
		return (-1);
	if ((eol = ft_strchr(buffers[fd], '\n')))
		return (copy_line(&buffers[fd], eol, line));
	while ((size = read(fd, input, BUFFER_SIZE)) > 0)
	{
		input[size] = '\0';
		tmp = buffers[fd];
		buffers[fd] = ft_strjoin(tmp, input);
		free_helper(&tmp, 0);
		eol = ft_strchr(buffers[fd], '\n');
		if (eol)
			break ;
	}
	if (size < 0)
		return (free_helper(&buffers[fd], -1));
	return (copy_line(&buffers[fd], eol, line));
}
