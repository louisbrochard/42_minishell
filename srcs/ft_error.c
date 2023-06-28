/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:12:23 by mgraaf            #+#    #+#             */
/*   Updated: 2023/06/28 19:07:57 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_message_error(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	ft_error(int error)
{
	if (error == 0)
		ft_message_error("malloc error");
	if (error == 1)
		ft_message_error("quotes error");
	if (error == 2)
		ft_message_error("token error");
	return (0);
}
