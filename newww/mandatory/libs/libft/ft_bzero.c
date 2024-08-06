/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 22:32:51 by aamardou          #+#    #+#             */
/*   Updated: 2022/10/04 01:26:37 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*bytes;
	size_t	i;

	bytes = (char *)s;
	i = 0;
	while (i < n)
	{
		bytes[i] = '\0';
		i++;
	}
}
