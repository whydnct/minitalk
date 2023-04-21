/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:38:09 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/21 15:08:03 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

sig_atomic_t volatile	g_signal_recieved;

void	safe_send_signal(pid_t pid, int sig, int runs)
{
	int i;

	i = 0;
	while (kill(pid, sig) == -1 && ++i < runs)
		usleep(10);
	if (i == runs)
		exit(1);
}

void	send_char(char c, pid_t srv_pid)
{
	char	i;
	int		safe_stop;

	i = 0;
	while (i <= 7)
	{
		safe_stop = 0;
		g_signal_recieved = 0;
		if (c & 1)
			safe_send_signal(srv_pid, SIGUSR1, 10);
		else
			safe_send_signal(srv_pid, SIGUSR2, 10);
		i++;
		c = c >> 1;
		while (!g_signal_recieved && ++safe_stop < 100)
			usleep(10);
		if (safe_stop == 100)
			exit(1);
	}
	g_signal_recieved = 0;
}

void	send_str(char *str, pid_t srv_pid)
{
	while (*str)
	{
		send_char(*str, srv_pid);
		str++;
	}
	send_char('\0', srv_pid);
	pause();
}

void	action(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signal == SIGUSR1)
		g_signal_recieved = 1;
	if (signal == SIGUSR2)
	{
		write(1, "\nOK\n", 4);
		exit(1);
	}
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
