/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:29:27 by aperez-m          #+#    #+#             */
/*   Updated: 2022/12/07 15:00:07 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r' || *nptr == '\n')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}	
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return ((int)(sign * res));
}
