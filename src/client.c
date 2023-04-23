/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:38:09 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/23 19:18:14 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, pid_t srv_pid)
{
	char	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			safe_send_signal(srv_pid, SIGUSR1, 50);
		else
			safe_send_signal(srv_pid, SIGUSR2, 50);
		i++;
		c = c >> 1;
		usleep(100);
	}
}

void	send_str(char *str, pid_t srv_pid)
{
	while (*str)
	{
		send_char(*str, srv_pid);
		str++;
	}
	send_char('\0', srv_pid);
}

int	main(int argc, char **argv)
{
	char				*str_to_pass;
	pid_t				srv_pid;

	if (argc != 3)
		return (0);
	srv_pid = ft_atoi(argv[1]);
	str_to_pass = argv[2];
	send_str(str_to_pass, srv_pid);
}
