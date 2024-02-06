/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarunota <jarunota@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:52:04 by jarunota          #+#    #+#             */
/*   Updated: 2024/02/06 17:48:02 by jarunota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*ft_read(int fd, char *buffer, char **backup)
char	*ft_gnl()
{
	while ()
	{

	}
}
char	*ft_cutline()
{
	while ()
	{

	}
}
char	*get_next_line(int fd)
{
	char		*buffer;
	char		*ans;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) *(BUFFER_SIZE + 1));
	if (!buffer)
	{
		if (backup)
			free(*backup);
		*backup = NULL;
		return (NULL);
	}
	ans = ft_read(fd, buffer, &backup);
	free(buffer);
	backup = ft_gnl(ans);
	ans = ft_cutline(ans);
	if (!ans)
	{
		if (backup)
			free(*backup);
		*backup = NULL;
		return (NULL);
	}
	return (ans);
}
