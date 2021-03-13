/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 19:35:31 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/12/31 16:07:43 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	init(char **buf, char **str)
{
	*buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*buf))
		return (0);
	if (!(*str))
	{
		*str = ft_strdup("");
		if (!(*str))
			return (0);
	}
	return (1);
}

static void	clear(char **p)
{
	free(*p);
	*p = NULL;
}

static int	output(int fd, char **line, int ret, char **str)
{
	char	*tmp;
	int		len;

	if (ret == -1)
	{
		clear(&str[fd]);
		return (-1);
	}
	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (!(*line = ft_substr(str[fd], 0, len)))
		return (-1);
	if (str[fd][len] == '\0')
	{
		clear(&str[fd]);
		return (0);
	}
	len++;
	if (!(tmp = ft_strdup(str[fd] + len)))
		return (-1);
	free(str[fd]);
	str[fd] = tmp;
	return (1);
}

static int	read_file(int fd, char **buf, char **str)
{
	int		ret;
	char	*tmp;

	while ((ret = read(fd, *buf, BUFFER_SIZE)) > 0)
	{
		(*buf)[ret] = '\0';
		tmp = ft_strjoin(*str, *buf);
		if (!tmp)
		{
			clear(buf);
			clear(str);
			return (-1);
		}
		free(*str);
		*str = tmp;
		if (ft_strchr(*str, '\n'))
			break ;
	}
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	static char	*str[OPEN_MAX];
	char		*buf;

	ret = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || !line || !(init(&buf, &str[fd])))
		return (-1);
	if (!ft_strchr(str[fd], '\n'))
		ret = read_file(fd, &buf, &str[fd]);
	clear(&buf);
	return (output(fd, line, ret, str));
}
