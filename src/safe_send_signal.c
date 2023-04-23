/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_send_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:04:50 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/23 10:18:48 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	safe_send_signal(pid_t pid, int sig, int runs)
{
	int	i;

	i = 0;
	while (kill(pid, sig) == -1 && ++i < runs)
	{
		if (sig == SIGUSR1)
			write(2, "error sending SIGUSR1\n", 23);
		else
			write(2, "error sending SIGUSR2\n", 23);
		usleep(10);
	}
	if (i == runs)
		exit(1);
}
