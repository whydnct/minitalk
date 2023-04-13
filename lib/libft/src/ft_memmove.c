/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:25:39 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/13 14:35:12 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = ((char *)src);
	d = ((char *)dest);
	if (s < d)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
		ft_memcpy(dest, s, n);
	return (dest);
}
