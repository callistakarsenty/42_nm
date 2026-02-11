/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:23:25 by ckarsent          #+#    #+#             */
/*   Updated: 2024/11/14 14:30:27 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = ft_strlen(little);
	if (j == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (big[i] && i + j <= len)
	{
		if (big[i] == little[0])
		{
			k = 0;
			while (k < j && big[i + k] == little[k])
				k++;
			if (k == j)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
