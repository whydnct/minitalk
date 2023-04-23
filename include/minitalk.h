/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:01:04 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/23 16:55:26 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _XOPEN_SOURCE 500
# define _POSIX_C_SOURCE 200112L

# include <signal.h>
# include <unistd.h>

# include "ft.h"

# define SEND_RETRIES 2
# define RUNS 100
void	safe_send_signal(pid_t pid, int sig, int runs);
#endif