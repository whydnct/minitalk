/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:38:09 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/30 21:36:26 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define _XOPEN_SOURCE 700
//#include <sys/types.h>
//#include <fcntl.h>
//#include <unistd.h>
#include <signal.h>
#include "../libft/src/libft.h"

sig_atomic_t volatile signal_recieved;

void	send_char(char c, int srv_pid)
{
	char	i;

	i = 0;
	while (i <= 7)
	{
		signal_recieved = 0;
		if (c & 1)
			kill(srv_pid, SIGUSR1);
		else
			kill(srv_pid, SIGUSR2);
		i++;
		c = c >> 1;
		while (!signal_recieved)
			pause();
	}
	signal_recieved = 0;
}

void	send_str(char *str, int srv_pid)
{
	while (*str)
	{
		send_char(*str, srv_pid);
		str++;
	}
	send_char('\0', srv_pid);
}

void	action(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signal == SIGUSR1)
		signal_recieved = 1;
}

//void	write_pid_to_file(void)
//{
//	int	fid;
//	int	pid;
//
//	pid = getpid();
//	fid = open("./server_id", O_WRONLY | O_CREAT, 0644);
//	ft_putnbr_fd(pid, fid);
//	close(fid);
//}

void	set_signal_action(void)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_sigaction = &action;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &sa, NULL);
}

int	main(int argc, char **argv)
{
	char				*str_to_pass;
	pid_t				srv_pid;

	signal_recieved = 0;
	if (argc != 3)
		return (0);
	srv_pid = ft_atoi(argv[1]);
	str_to_pass = argv[2];
	set_signal_action();
	send_str(str_to_pass, srv_pid);
}
