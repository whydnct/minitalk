/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:38:09 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/24 08:21:43 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 700
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "../../libft/src/libft.h"

int srv_pid;

void	send_char(char c, int srv_pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & 1)
			kill(srv_pid, SIGUSR1);
		else
			kill(srv_pid, SIGUSR2);
		i--;
		c >> 1;
		//pause();
		if(usleep(200))
			write(1, "error usleep", 12);
	}
}

void	send_str(char *str, int srv_pid)
{
	while (*str)
	{
		send_char(*str, srv_pid);
		str++;
	}
	send_char(*str, srv_pid);
}

//void	action(int signal, siginfo_t *info, void *context)
//{
//	(void)context;
//	if (srv_pid == info->si_pid)
//	{

//	}
//}

int	main(int argc, char **argv)
{
	//struct sigaction	sa;
	char				*str_to_pass;

	if (argc != 3)
		return (0);
	srv_pid = ft_atoi(argv[1]);
	str_to_pass = argv[2];
//	sa.sa_sigaction = &action;
//	sa.sa_flags = SA_SIGINFO;
//	sigemptyset(&sa.sa_mask);
//	sigaction(SIGUSR1, &sa, NULL);
//	sigaction(SIGUSR2, &sa, NULL);
	send_str(str_to_pass, srv_pid);

}
