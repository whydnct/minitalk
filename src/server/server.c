/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:22:31 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/28 20:38:22 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 700
#include <sys/types.h>
#include <unistd.h>
#include "../../libft/src/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>

sig_atomic_t	flag;

void	char_printer(int bit, int client_pid)
{
	static int				i = 0;
	static unsigned char	c = 0;
	static int				signal_dest = 0;

	if (!signal_dest)
		signal_dest = client_pid;
	if (i <= 7)
	{
		c |= (bit << i);
		i++;
		kill(signal_dest, SIGUSR1);
	}
	if (i > 7)
	{
		if (c)
			write(1, &c, 1);
		else
		{
			kill(signal_dest, SIGUSR2);
			signal_dest = 0;
		}
		c = 0;
		i = 0;
	}
}

void	action(int signal, siginfo_t *info, void *context)
{
	(void)context;
	flag = 0;
	if (signal == SIGUSR1)
		flag = 1;
	char_printer(flag, info->si_pid);
}

void	set_signal_action(void)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_sigaction = &action;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	pid_t				pid;
	int					fid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	fid = open("./_id", O_WRONLY | O_CREAT, 0644);
	ft_putnbr_fd(pid, fid);
	close(fid);
	set_signal_action;
	while (1)
	{
		pause();
	}
}
