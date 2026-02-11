/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <ckarsent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:41:00 by ckarsent          #+#    #+#             */
/*   Updated: 2024/11/14 17:22:13 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	find;
	int	count;

	i = 0;
	find = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && find == 0)
		{
			find = 1;
			count++;
		}
		else if (s[i] == c)
			find = 0;
		i++;
	}
	return (count);
}

static int	ft_2strlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*little_split(char const *s, int len)
{
	char	*st;
	int		i;

	i = 0;
	st = malloc(sizeof(char) * (len + 1));
	if (!st)
		return (NULL);
	while (i < len)
	{
		st[i] = s[i];
		i++;
	}
	st[i] = '\0';
	return (st);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words;
	int		j;
	int		len;

	words = count_words(s, c);
	str = malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (*s && j < words)
	{
		if (*s != c)
		{
			len = ft_2strlen(s, c);
			str[j] = little_split(s, len);
			if (!str[j])
				return (NULL);
			s += len;
			j++;
		}
		s++;
	}
	str[j] = (NULL);
	return (str);
}
