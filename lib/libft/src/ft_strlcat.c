/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 04:48:10 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/13 14:36:25 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_l;

	i = 0;
	dst_l = ft_strlen(dst);
	if (dst_l >= size)
		return (size + ft_strlen((char *)src));
	while ((i < size - dst_l - 1) && src[i])
	{
		dst[dst_l + i] = src[i];
		i++;
	}
	dst[dst_l + i] = 0;
	return (dst_l + ft_strlen((char *)src));
}

/*
si queda algún bite libre en dst
cogen el tamaño total del buffer
añade src al final de dst
copia como mucho size - strlen(src) - 1
y termina con \0


retorna (dst_l + src_l)
strlcat() appends string src to the end of	dst.
It will append at most dstsize - strlen(dst) - 1 characters.
It will then NUL-terminate
	unless dstsize is 0 or
	the original dst string > dstsize
		it means that either dstsize is incorrect
		or dst is not a proper string).



*/