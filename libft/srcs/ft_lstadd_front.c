/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:40:44 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/28 18:06:08 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *ne)
{
	if (lst)
	{
		if (*lst)
			ne->next = *lst;
		*lst = ne;
	}
}
