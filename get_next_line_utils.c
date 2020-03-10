/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agourrag <agourrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:29:49 by agourrag          #+#    #+#             */
/*   Updated: 2020/03/10 00:08:39 by agourrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	int res;

	if (!str)
		return (0);
	res = 0;
	while (str[res])
		res++;
	return (res);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t i;

	if (!src)
	{
		dst = 0;
		return (0);
	}
	i = -1;
	while (src[++i] && i < n - 1)
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	char	*res;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(res = malloc(len)))
		return (0);
	ft_strlcpy(res, s1, len);
	ft_strlcpy(res + ft_strlen(s1), s2, len);
	return (res);
}

char		*ft_strchr(const char *str, const char c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return ((char*)str);
		str++;
	}
	if (*str == c)
		return ((char*)str);
	return (0);
}

char		*ft_strdup(const char *str)
{
	int		len;
	char	*res;

	len = ft_strlen(str) + 1;
	if (!(res = malloc(len)))
		return (NULL);
	ft_strlcpy(res, str, len);
	return (res);
}
