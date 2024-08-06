/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 02:39:35 by aamardou          #+#    #+#             */
/*   Updated: 2022/10/22 16:44:58 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_i;
	char			*p;
	size_t			p_i;

	s_i = 0;
	p_i = 0;
	if (len > ft_strlen (s))
		p = ft_calloc(ft_strlen (s) + 1, 1);
	else
		p = ft_calloc(len + 1, 1);
	if (!p || !s)
		return (0);
	while (s[s_i] != '\0')
	{
		if (s_i >= start && p_i < len)
		{
			p[p_i] = ((char *)s)[s_i];
			p_i++;
		}
		s_i++;
	}
	return (p);
}
