/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 08:21:13 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/13 14:37:00 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_2;
	size_t	i;
	size_t	l_max;
	size_t	s_len;

	s_len = ft_strlen(s);
	i = 0;
	if ((long)(s_len - start) < 0)
		l_max = 0;
	else if (s_len - start > len)
		l_max = len;
	else
		l_max = s_len - start;
	s_2 = malloc(l_max + 1);
	if (s_2 == NULL)
		return (NULL);
	while (i < l_max && s[start + i])
	{
		s_2[i] = s[start + i];
		i++;
	}
	s_2[i] = 0;
	return (s_2);
}
