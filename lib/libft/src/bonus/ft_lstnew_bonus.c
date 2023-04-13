/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:31:13 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/13 14:38:06 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*item;

	item = (t_list *)malloc(sizeof(t_list));
	if (!item)
		return (NULL);
	item->content = content;
	item->next = NULL;
	return (item);
}

/*
int main()
{
	char	*content;
	t_list	**lista;

	content = "contenido";
	lista = malloc(sizeof(t_list **));
	ft_lstadd_front(lista, ft_lstnew(content));
	ft_putstr_fd((*lista)->content, 1);

}
*/