/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarunota <jarunota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:17:12 by jarunota          #+#    #+#             */
/*   Updated: 2024/02/09 15:08:09 by jarunota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifdef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t		ft_strlen(const char *s);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
static char	*ft_read(int fd, char **backup);
static char	*ft_cutline(char **backup);
char		*get_next_line(int fd);

#endif
