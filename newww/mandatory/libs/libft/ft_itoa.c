/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:37:14 by aamardou          #+#    #+#             */
/*   Updated: 2022/10/22 15:59:51 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	calc_digits(long n)
{
	int	ret;

	ret = 0;
	if (n < 0)
	{
		n *= -1;
		ret++;
	}
	while (n > 0)
	{
		n = n / 10;
		ret++;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	long	l;
	int		n_digits;
	char	*ret;

	l = n;
	if (!n)
		return (ft_strdup("0"));
	n_digits = calc_digits(l);
	ret = (char *)malloc(sizeof(char) * (n_digits + 1));
	if (!ret)
		return (NULL);
	ret[n_digits--] = '\0';
	if (l < 0)
	{
		ret[0] = '-';
		l *= -1;
	}
	while (l > 0)
	{
		ret[n_digits] = '0' + (l % 10);
		n_digits--;
		l /= 10;
	}
	return (ret);
}
