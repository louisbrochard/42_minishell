/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:45:34 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/28 18:06:18 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *ne)
{
	t_list	*lst_bis;

	lst_bis = ft_lstlast(*lst);
	if (lst_bis == NULL)
		*lst = ne;
	else
		lst_bis->next = ne;
}
