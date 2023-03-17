/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:22:31 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/17 16:56:11 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 700
#include <sys/types.h>
#include <unistd.h>
#include "../../libft/src/libft.h"
#include <signal.h>
#include <stdlib.h>

int	c;

void	sigusr1_handler()
{
		c++;
}

void	sigusr2_handler()
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
	struct sigaction	sa1;
	struct sigaction	sa2;
	pid_t				pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	c = 0;
	sa1.sa_handler = &sigusr1_handler;
	sa1.sa_flags = SA_SIGINFO;
    sigemptyset(&sa1.sa_mask);
	sa2.sa_handler = &sigusr2_handler;
	sa2.sa_flags = SA_SIGINFO;
    sigemptyset(&sa2.sa_mask);
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	while (1)
	{
		pause();
	}
}
