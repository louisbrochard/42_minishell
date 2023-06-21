/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:26:51 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/21 18:41:21 by louisbrocha      ###   ########.fr       */
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
    char *tmp;

    tools->args = readline("minishell> ");
    tmp = ft_strtrim(tools->args, " ");
    free(tools->args);
    tools->args = tmp;
    if (!ft_strncmp(tools->args, "exit", ft_strlen(tools->args)) && tools->args[0] != '\0')
        exit(0);
    add_history(tools->args);
    ft_reset(tools);
    return (0);
}