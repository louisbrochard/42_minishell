/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:26:51 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/28 19:08:24 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_reset(t_tools *tools)
{
    free(tools->args);
    tools->args = NULL;
    free_list(tools->lexer_list);
    ft_init_tools(tools);
    minishell_loop(tools);
    return (0);
}

int minishell_loop(t_tools *tools)
{
    char *tmp;

    tools->args = readline("minishell> ");
    tmp = ft_strtrim(tools->args, " "); // pour enlever les espaces avant et apres
    free(tools->args);
    tools->args = tmp;
    if (!ft_strncmp(tools->args, "exit", ft_strlen(tools->args)) && tools->args[0] != '\0') // gérer l'exit
        exit(0);
    add_history(tools->args); // pour ajouter la commande a l'historique
    if (check_quotes(tools->args) == 0) // pour checker si les quotes sont bien fermées (nombre pair de " et ')
        return (ft_error(1));
    if (ft_token_reader(tools) == 1) // pour lire les tokens, stocke les tokens (|, >, >>, <, <<) dans tools->lexer_list
        return (ft_error(2));
    ft_reset(tools); // pour reset les args et relancer le minishell_loop
    return (0);
}