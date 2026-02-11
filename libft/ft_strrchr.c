/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:33:50 by ckarsent          #+#    #+#             */
/*   Updated: 2024/11/14 15:31:59 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*j;
	char	*s1;

	i = 0;
	j = NULL;
	s1 = (char *)s;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			j = &s1[i];
		i++;
	}
	if ((unsigned char)c == '\0')
		return (&s1[i]);
	return (j);
}
