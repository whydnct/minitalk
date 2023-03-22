/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:38:09 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/22 20:43:47 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../libft/src/libft.h"
#include <signal.h>

void	send_char(char c, int srv_pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i)) 
			kill(srv_pid, SIGUSR1);
		else
			kill(srv_pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

void	send_str(char *str, int srv_pid)
{
	while (*str)
	{
		send_char(*str, srv_pid);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int		srv_pid;
	char	*str_to_pass;

	srv_pid = ft_atoi(argv[1]);
	if (argc != 3 || srv_pid < 2)
		return (0);
	str_to_pass = argv[2];
	send_str(str_to_pass, srv_pid);
}
