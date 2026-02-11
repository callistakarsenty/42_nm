/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:44:11 by ckarsent          #+#    #+#             */
/*   Updated: 2024/11/14 11:56:44 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*c;

	if (start >= ft_strlen(s))
	{
		c = malloc(sizeof(char));
		if (!c)
			return (NULL);
		c[0] = '\0';
		return (c);
	}
	c = malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		c[i] = s[i + start];
		i++;
	}
	c[i] = '\0';
	return (c);
}
