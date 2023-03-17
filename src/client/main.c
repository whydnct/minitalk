/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:38:09 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/17 16:48:03 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../libft/src/libft.h"
#include <signal.h>

void	char_to_sigusr1(char c, int srv_pid)
{
	int	i;

	i = 0;
	while (i <= c)
	{
		kill(srv_pid, SIGUSR1);
		i++;
		usleep(100);
	}
	kill(srv_pid, SIGUSR2);
}

void	send_str(char *str, int srv_pid)
{
	while (*str)
	{
		write(1, str, 1);
		char_to_sigusr1(*str, srv_pid);
		str++;
	}
	write(1, "\n", 1);
	kill(srv_pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	int		srv_pid;
	char	*str_to_pass;

	(void)argc;
	srv_pid = ft_atoi(argv[1]);
	str_to_pass = argv[2];
	send_str(str_to_pass, srv_pid);
}
