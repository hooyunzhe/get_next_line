/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun-zhe <hyun-zhe@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:54:53 by hyun-zhe          #+#    #+#             */
/*   Updated: 2021/06/23 22:56:05 by hyun-zhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = -1;
	str = malloc((ft_strlen(s1) * sizeof(char)) + 1);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = 0;
	return (str);
}

char	*ft_strtrimchr(const char *str, char c)
{
	int		i;
	int		len;
	char	*newstr;

	if (!str)
		return (NULL);
	if (ft_strchr(str, c))
	{
		i = -1;
		len = ft_strlen(str) - ft_strlen(ft_strchr(str, c));
		newstr = malloc((len * sizeof(char)) + 1);
		while (str[++i] != c)
			newstr[i] = str[i];
		newstr[i] = 0;
	}
	else
		newstr = ft_strdup(str);
	return (newstr);
}

char	*ft_strupdate(char *s1, const char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*newstr;

	if (s1)
	{
		i = 0;
		len = ft_strlen(s1) + ft_strlen(s2);
		newstr = malloc((len * sizeof(char)) + 1);
		if (!newstr)
			return (NULL);
		j = 0;
		while (s1[j])
			newstr[i++] = s1[j++];
		j = 0;
		while (s2[j])
			newstr[i++] = s2[j++];
		newstr[i] = 0;
		free(s1);
		s1 = NULL;
	}
	else
		newstr = ft_strdup(s2);
	return (newstr);
}
