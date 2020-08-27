/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 22:23:53 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/29 21:10:42 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_gnl_join(char *s1, char *s2)
{
	char		*res;

	if (!s1 || !s2 || !(res = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcpy(res + ft_strlen(s1), s2);
	ft_strdel(&s1);
	return (res);
}

static void		gnl_s_r(char **s, int i)
{
	char		*temp;

	temp = ft_strdup(*s + i + 1);
	free(*s);
	*s = temp;
	temp = NULL;
}

int				get_next_line(const int fd, char **line)
{
	static char	*s[MAX_FD + 1];
	char		buffer[BUFF_SIZE + 1];
	int			i;
	int			read_status;

	if (read(fd, NULL, 0) < 0)
		return (-1);
	if (!s[fd])
		s[fd] = ft_strnew(0);
	while ((read_status = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[read_status] = '\0';
		s[fd] = ft_gnl_join(s[fd], buffer);
		if (ft_strchr(buffer, ENTER))
			break ;
	}
	if ((!s[fd] || !*s[fd]) && read_status == 0)
		return (0);
	i = 0;
	while (s[fd][i] != '\n' && s[fd][i])
		i++;
	*line = ft_strsub(s[fd], 0, i);
	(ft_strlen(*line) < ft_strlen(s[fd])) ?
		gnl_s_r(&s[fd], i) : ft_strdel(&s[fd]);
	return (1);
}
