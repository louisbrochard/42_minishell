/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:26:51 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/21 12:26:53 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_reset(t_tools *tools)
{
    free(tools->args);
    tools->args = NULL;
    minishell_loop(tools);
    return (0);
}

int minishell_loop(t_tools *tools)
{
    tools->args = readline("minishell> ");
    printf("OK\n");
    if (!ft_strncmp(tools->args, "exit",4))
    {
        printf("exit\n");
        exit(0);
    }
    ft_reset(tools);
    return (0);
}