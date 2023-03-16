/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:59:23 by aperez-m          #+#    #+#             */
/*   Updated: 2022/12/04 08:50:36 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while ((i < (dstsize - 1)) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen((char *)src));
}
