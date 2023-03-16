/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:38:09 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/16 19:39:17 by aperez-m         ###   ########.fr       */
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
	}
	kill(srv_pid, SIGUSR2);
}

void	send_str(char *str, int srv_pid)
{
	while (*str)
	{
		char_to_sigusr1(*str, srv_pid);
		str++;
	}
	kill(srv_pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	int		srv_pid;
	char	*str_to_pass;

	srv_pid = ft_atoi(argv[0]);
	str_to_pass = argv[1];
	send_str(str_to_pass, srv_pid);
}
