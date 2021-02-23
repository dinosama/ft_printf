/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:19:47 by aaapatou          #+#    #+#             */
/*   Updated: 2019/11/14 01:11:07 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (0);
	tmp = 0;
	while (lst)
	{
		if (!(list = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&tmp, del);
			return (0);
		}
		ft_lstadd_back(&tmp, list);
		lst = lst->next;
	}
	return (tmp);
}
