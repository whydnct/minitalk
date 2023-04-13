/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:39:39 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/13 14:34:53 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int	get_nbr_size(int i)
{
	int	n_size;

	n_size = 1;
	while (i / 10)
	{
		n_size++;
		i /= 10;
	}
	return (n_size);
}

static	void	fill_str(char *str, int flag, int n_size, unsigned int n_dummy)
{
	while (flag + n_size - 1 >= 0 + flag)
	{
		str[flag + n_size - 1] = 48 + (n_dummy % 10);
		n_dummy /= 10;
		n_size--;
	}
}

char	*ft_itoa(int n)
{
	char			*str;
	int				n_size;
	int				flag;
	unsigned int	n_dummy;

	flag = 0;
	if (n < 0)
	{
		flag = 1;
		n_dummy = (unsigned int)(-1 * n);
	}
	else
		n_dummy = n;
	n_size = get_nbr_size(n_dummy);
	str = (char *)malloc((flag + n_size + 1));
	if (str == NULL)
		return (NULL);
	str[flag + n_size] = 0;
	fill_str(str, flag, n_size, n_dummy);
	if (flag == 1)
		str[0] = '-';
	return (str);
}
