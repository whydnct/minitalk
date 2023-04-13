/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:53:39 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/13 14:36:05 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static	int	get_w_len(char const *s, char c)
{
	int	w_len;

	w_len = 0;
	while (s[w_len] != c && s[w_len])
		w_len++;
	return (w_len);
}

static	int	get_w_nbr(char const *s, char c)
{
	int	i;
	int	w_nbr;

	i = 0;
	w_nbr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			w_nbr++;
		while (s[i] != c && s[i])
			i++;
	}
	return (w_nbr);
}

static	char	**err_free(char **list, int i)
{
	while (i > 0)
	{
		i--;
		free(list[i]);
	}
	free(list);
	return (NULL);
}

char	**build_list(char **ret, char const *s, char c)
{
	int	w_len;
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			w_len = get_w_len(s, c);
			ret[i] = (char *)malloc(w_len + 1);
			if (!ret[i])
				return (err_free(ret, i));
			ft_strlcpy(ret[i], s, w_len + 1);
			i++;
			s += w_len;
		}
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		w_nbr;

	w_nbr = get_w_nbr(s, c);
	ret = (char **)malloc((w_nbr + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	if (!build_list(ret, s, c))
		return (NULL);
	ret[w_nbr] = (char *) 0;
	return (ret);
}
