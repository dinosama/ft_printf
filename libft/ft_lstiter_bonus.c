/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:02:31 by aaapatou          #+#    #+#             */
/*   Updated: 2019/11/07 02:32:52 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list		*temp;

	if (!(temp = lst))
		return ;
	while (temp != NULL)
	{
		f(temp->content);
		temp = temp->next;
	}
}
