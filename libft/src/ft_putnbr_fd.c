/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:24:11 by aperez-m          #+#    #+#             */
/*   Updated: 2022/12/06 12:56:57 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n_dummy;

	if (n < 0)
	{
		n_dummy = -1 * n;
		ft_putchar_fd('-', fd);
	}
	else
		n_dummy = n;
	if (!(n_dummy / 10))
		ft_putchar_fd((n_dummy + 48), fd);
	else
	{
		ft_putnbr_fd(n_dummy / 10, fd);
		ft_putchar_fd(n_dummy % 10 + 48, fd);
	}
}
