/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 22:23:50 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/06/11 19:04:59 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*copy_s1;
	size_t	len;
	size_t	cnt;

	len = ft_strlen(s1) + 1;
	copy_s1 = (char *)malloc(sizeof(char) * len);
	if (!copy_s1)
		return (NULL);
	cnt = 0;
	while (*s1)
		copy_s1[cnt++] = *(s1++);
	copy_s1[cnt] = '\0';
	return (copy_s1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	cnt;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	cnt = 0;
	while (*s1)
		str[cnt++] = *(s1++);
	while (*s2)
		str[cnt++] = *(s2++);
	str[cnt] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*p_substr;

	if (!s)
		return (NULL);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	p_substr = substr;
	while (len && start < ft_strlen(s) && s[start])
	{
		*p_substr = s[start];
		p_substr++;
		start++;
		len--;
	}
	*p_substr = '\0';
	return (substr);
}
