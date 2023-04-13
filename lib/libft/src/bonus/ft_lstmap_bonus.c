/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:05:34 by aperez-m          #+#    #+#             */
/*   Updated: 2023/04/13 14:38:01 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Itera la lista ’lst’ y aplica la función ’f’ al contenido de
cada nodo. Crea una lista resultante de la aplicación correcta
y sucesiva de la función ’f’ sobre cada nodo. La función ’del’
se utiliza para eliminar el contenido de un nodo, si hace falta.*/

#include "ft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*new_node;

	ret = 0;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, new_node);
		lst = lst->next;
	}
	return (ret);
}
