/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:40:33 by aamardou          #+#    #+#             */
/*   Updated: 2022/10/22 16:40:39 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		wordindex;
	char	*str;
	int		strindex;

	if (!s1 || !s2)
		return (0);
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, 1);
	wordindex = 0;
	strindex = 0;
	if (!str)
		return (0);
	while (s1[wordindex] != '\0')
	{
		str[strindex++] = s1[wordindex++];
	}
	wordindex = 0;
	while (s2[wordindex] != '\0')
	{
		str[strindex++] = s2[wordindex++];
	}
	str[strindex] = '\0';
	return (str);
}
