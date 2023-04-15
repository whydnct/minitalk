/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:38:09 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/15 07:39:29 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

sig_atomic_t volatile	g_signal_recieved;

void	send_char(char c, int srv_pid)
{
	char	i;

	i = 0;
	while (i <= 7)
	{
		g_signal_recieved = 0;
		if (c & 1)
		{
			while (kill(srv_pid, SIGUSR1) == -1)
				usleep(1);
		}
		else
		{
			while (kill(srv_pid, SIGUSR2) == -1)
				usleep(1);
		}
		i++;
		c = c >> 1;
		while (!g_signal_recieved)
			usleep(10);
	}
	g_signal_recieved = 0;
}

void	send_str(char *str, int srv_pid)
{
	while (*str)
	{
		send_char(*str, srv_pid);
		str++;
	}
	send_char('\0', srv_pid);
	usleep(50);
}

void	action(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signal == SIGUSR1)
		g_signal_recieved = 1;
	if (signal == SIGUSR2)
		write(1, "\nOK\n", 4);
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

int	main(int argc, char **argv)
{
	char				*str_to_pass;
	pid_t				srv_pid;

	g_signal_recieved = 0;
	if (argc != 3)
		return (0);
	srv_pid = ft_atoi(argv[1]);
	str_to_pass = argv[2];
	set_signal_action();
	send_str(str_to_pass, srv_pid);
}
