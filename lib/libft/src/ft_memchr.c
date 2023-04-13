/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:00:35 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/13 14:34:58 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c_1;
	unsigned char	*s_1;

	c_1 = (unsigned char)c;
	s_1 = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (c_1 != *s_1 && n-- > 1)
		s_1++;
	if (n == 0)
		return (NULL);
	return (s_1);
}
