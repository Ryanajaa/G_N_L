/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarunota <jarunota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:52:04 by jarunota          #+#    #+#             */
/*   Updated: 2024/02/09 22:25:35 by jarunota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char	*ft_cutline(char **backup)
{
	char	*line;
	char	*temp_backup;
	int		i;

	i = 0;
	while ((*backup)[i] && (*backup)[i] != '\n')
		i++;
	line = ft_substr(*backup, 0, i);
	temp_backup = *backup;
	*backup = ft_substr(*backup, i + 1, ft_strlen(*backup) - i);
	free(temp_backup);
	if (!line || !*backup)
	{
		free(line);
		free(*backup);
		return (NULL);
	}
	return (line);
}

static char	*ft_read(int fd, char **backup)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp_backup;
	int		read_result;

	read_result = read(fd, buf, BUFFER_SIZE);
	if (read_result == -1 || read_result == 0)
	{
		if (*backup)
			free(*backup);
		*backup = NULL;
		return (NULL);
	}
	buf[read_result] = '\0';
	temp_backup = *backup;
	*backup = ft_strjoin(temp_backup, buf);
	free(temp_backup);
	if (!*backup)
		return (NULL);
	return (*backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (!ft_strchr(backup, '\n'))
	{
		if (!ft_read(fd, &backup))
		{
			free(line);
			return (NULL);
		}
	}
	line = ft_cutline(&backup);
	if (!line)
		return (NULL);
	return (line);
}

/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/