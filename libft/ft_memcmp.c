/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:59:47 by ckarsent          #+#    #+#             */
/*   Updated: 2024/11/14 12:07:47 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sun;
	unsigned char	*sdeux;

	i = 0;
	sun = (unsigned char *)s1;
	sdeux = (unsigned char *)s2;
	while (i < n)
	{
		if (sun[i] != sdeux[i])
			return (sun[i] - sdeux[i]);
		i++;
	}
	return (0);
}
