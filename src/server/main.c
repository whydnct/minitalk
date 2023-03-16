/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:22:31 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/16 20:15:16 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "../../libft/src/libft.h"

int	c;

void	sigusr1_handler(void)
{
	c++;
}

void	sigusr2_handler(void)
{
	if (c == 0)
		write(1, "\n", 1);
	else
	{
		write(1, &c, 1);
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	c = 0;
	while (1)
	{
		//pause();
		sigusr1_handler();
		sigusr2_handler();
	}
}
