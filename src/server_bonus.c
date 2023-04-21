/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:22:31 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/21 15:24:59 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_printer(int bit, int client_pid)
{
	static int				i = 0;
	static unsigned char	c = 0;
	int						safe_stop;

	safe_stop = 0;
	c |= (bit << i);
	i++;
	while (kill(client_pid, SIGUSR1) == -1 && ++safe_stop < 10)
		write(2, "error sending SIGUSR1 to client\n", 33);
	if (safe_stop == 10)
		exit(1);
	if (i > 7)
	{
		if (c)
			write(1, &c, 1);
		else
		{
			while (kill(client_pid, SIGUSR2) == -1 && ++safe_stop < 20)
				write(2, "error sending SIGUSR2 to client\n", 33);
			if (safe_stop == 20)
				exit(1);
		}
		c = 0;
		i = 0;
	}
}

void	action(int signal, siginfo_t *info, void *context)
{
	(void)context;
	char_printer(signal == SIGUSR1, info->si_pid);
}

void	set_signal_action(void)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_sigaction = &action;
	sa.sa_flags = SA_SIGINFO;
	sigfillset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	pid_t				pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	set_signal_action();
	while (1)
		pause();
}
