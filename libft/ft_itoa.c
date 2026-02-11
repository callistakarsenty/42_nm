/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <ckarsent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:35:49 by ckarsent          #+#    #+#             */
/*   Updated: 2024/11/14 17:21:32 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int nb)
{
	int			count;
	long int	i;

	count = 1;
	i = nb;
	if (nb < 0)
	{
		i *= (-1);
		count++;
	}
	while (i >= 10)
	{
		i /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*nb;
	long int	nbr;
	int			i;
	int			sign;

	nbr = n;
	i = ft_nbrlen(n);
	nb = malloc(sizeof(char) * (i + 1));
	if (!nb)
		return (NULL);
	nb[i] = '\0';
	sign = 0;
	if (nbr < 0)
	{
		nb[0] = '-';
		nbr *= (-1);
		sign = 1;
	}
	while (--i >= sign)
	{
		nb[i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (nb);
}
