/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:15:40 by aamardou          #+#    #+#             */
/*   Updated: 2024/08/05 06:50:45 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char *save, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(save, buffer);
	free(save);
	return (temp);
}

char	*ft_save(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 2), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free (buffer);
	return (line);
}

char	*ft_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	s = ft_substr(save, 0, i + 1);
	return (s);
}

char	*ft_read(int fd, char *res)
{
	char	*buffer;
	int		bit_read;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bit_read = 1;
	while (bit_read > 0)
	{
		bit_read = read(fd, buffer, BUFFER_SIZE);
		if (bit_read < 0)
		{
			free(res);
			res = NULL;
			break ;
		}
		buffer[bit_read] = 0;
		res = ft_free(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*res;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd == 1 || fd == 2)
		return (NULL);
	res = ft_read(fd, res);
	if (!res)
		return (NULL);
	line = ft_line(res);
	res = ft_save(res);
	return (line);
}
