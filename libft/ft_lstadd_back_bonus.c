/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:34:34 by aaapatou          #+#    #+#             */
/*   Updated: 2019/11/04 22:30:57 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list		*temp;

	temp = *alst;
	if (temp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	else
	{
		*alst = new;
	}
}
