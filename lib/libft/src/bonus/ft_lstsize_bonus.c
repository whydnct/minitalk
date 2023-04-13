/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:39:57 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/13 14:38:10 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_lstsize(t_list *lst)
{
	int		lstsize;

	lstsize = 0;
	while (lst)
	{
		lstsize++;
		lst = lst->next;
	}
	return (lstsize);
}
