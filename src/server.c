/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:22:31 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/30 21:35:15 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define _XOPEN_SOURCE 700
//#include <sys/types.h>
//#include <fcntl.h>
//#include <unistd.h>
#include <signal.h>
#include "../libft/src/libft.h"

void	char_printer(int bit, int client_pid)
{
	static int				i = 0;
	static unsigned char	c = 0;

	if (i <= 7)
	{
		c |= (bit << i);
		i++;
		kill(client_pid, SIGUSR1);
	}
	if (i > 7)
	{
		if (c)
			write(1, &c, 1);
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
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

//void	write_pid_to_file(pid_t pid)
//{
//	int	fid;
//
//	fid = open("./_id", O_WRONLY | O_CREAT, 0644);
//	ft_putnbr_fd(pid, fid);
//	close(fid);
//}

int	main(void)
{
	pid_t				pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	set_signal_action();
	while (1)
	{
		pause();
	}
}
