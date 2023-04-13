/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:33:53 by aperez-m          #+#    #+#             */
/*   Updated: 2022/12/03 10:24:29 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_a;
	unsigned char	*s_b;
	size_t			i;

	i = 0;
	s_a = (unsigned char *)s1;
	s_b = (unsigned char *)s2;
	while (i < n && s_a[i] == s_b[i])
		i++;
	if (!(i < n))
		return (0);
	return ((int)(s_a[i] - s_b[i]));
}
