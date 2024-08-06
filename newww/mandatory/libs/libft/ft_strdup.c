/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 05:05:26 by aamardou          #+#    #+#             */
/*   Updated: 2022/10/17 05:11:33 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1length;
	char	*p;
	int		i;

	s1length = ft_strlen(s1) + 1;
	i = 0;
	p = ft_calloc(s1length, 1);
	if (!p)
		return (0);
	while (s1[i] != '\0')
	{	
	p[i] = s1[i];
	i++;
	}
	p[i] = '\0';
	return (p);
}
