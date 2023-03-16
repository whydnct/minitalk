/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:22:31 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/16 21:27:39 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "../../libft/src/libft.h"
#include <signal.h>
#include <stdlib.h>
#define _XOPEN_SOURCE 700

int	c;

void	sigusr1_handler(int sig)
{
	c++;
}

void	sigusr2_handler(int sig)
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
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	c = 0;
	sa.sa_handler_sigusr1 = &sigusr1_handler;
	sa.sa_handler_sigusr2 = &sigusr2_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
