/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <ckarsent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:09:20 by ckarsent          #+#    #+#             */
/*   Updated: 2024/11/14 17:22:40 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(char s, char const *c)
{
	int		i;

	i = 0;
	while (c[i])
	{
		if (s == c[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*c;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_find(s1[i], set))
		i++;
	while (j > i && ft_find(s1[j], set))
		j--;
	c = malloc(sizeof(char) * (j - i + 2));
	if (!c)
		return (NULL);
	k = 0;
	while (i <= j)
	{
		c[k] = s1[i];
		k++;
		i++;
	}
	c[k] = '\0';
	return (c);
}
