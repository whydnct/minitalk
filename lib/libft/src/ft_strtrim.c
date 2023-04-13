/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:53:08 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/13 14:36:55 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static	int	get_start(char *s1, char *set)
{
	int	start;

	start = 0;
	while (s1[start])
	{
		if (!ft_strchr(set, s1[start]))
			break ;
		start++;
	}
	return (start);
}

static int	get_end(char *s1, char *set)
{
	size_t	end;	

	if (ft_strlen(s1) == 0)
		return (0);
	end = ft_strlen(s1) - 1;
	while (s1[end])
	{
		if (!ft_strchr(set, s1[end]))
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s_ret;
	int		end;
	int		start;
	int		i;

	start = get_start((char *)s1, (char *)set);
	end = get_end((char *)s1, (char *)set);
	if (end - start < 0 || (ft_strlen(s1) == 0))
	{
		s_ret = malloc(1);
		if (s_ret == NULL)
			return (NULL);
		s_ret[0] = '\0';
		return (s_ret);
	}
	s_ret = (char *)malloc(end - start + 2);
	if (s_ret == NULL)
		return (NULL);
	i = -1;
	while (++i < (end - start + 1))
		s_ret[i] = s1[start + i];
	s_ret[i] = '\0';
	return (s_ret);
}
