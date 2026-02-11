/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:05:09 by ckarsent          #+#    #+#             */
/*   Updated: 2024/11/14 15:36:26 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*s1;
	unsigned char	c1;

	i = 0;
	s1 = (char *)s;
	c1 = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == c1)
			return (&s1[i]);
		i++;
	}
	if (c1 == '\0')
		return (&s1[i]);
	return (00);
}
