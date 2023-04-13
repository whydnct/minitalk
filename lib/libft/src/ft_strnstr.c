/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:46:42 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/13 14:36:46 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	long	i;
	long	j;
	size_t	b_l;
	size_t	l_l;

	i = 0;
	j = 0;
	b_l = ft_strlen((char *)big);
	l_l = ft_strlen((char *)little);
	if (!little[0])
		return ((char *)big);
	if (len < l_l)
		return (NULL);
	if (len > b_l)
		len = b_l;
	while ((i <= (long)(len - l_l)) && (i <= (long)(b_l - l_l)))
	{
		while ((big[i + j] == little[j]) && little[j] && big[i + j])
			j++;
		if (!little[j])
			return ((char *)big + i);
		j = 0;
		i++;
	}
	return (NULL);
}
