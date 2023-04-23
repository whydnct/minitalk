/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:22:31 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/23 18:56:35 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_printer(int bit, int client_pid)
{
	static int				i = 0;
	static unsigned char	c = 0;

	c |= (bit << i);
	i++;
	safe_send_signal(client_pid, SIGUSR1, SEND_RETRIES);
	if (i == 8)
	{
		if (c)
			write(1, &c, 1);
		else
			safe_send_signal(client_pid, SIGUSR2, SEND_RETRIES);
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
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
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
