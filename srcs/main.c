/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:26:26 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/28 18:41:05 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    ft_init_tools(t_tools *tools)
{
    tools->args = NULL;
    tools->lexer_list = malloc(sizeof(t_lexer));
    if (!tools->lexer_list)
        exit(0);
    tools->lexer_list->token = NULL;
    tools->lexer_list->next = NULL;
    tools->pipes = 0;
}

int main(int argc, char **argv, char **envp)
{
    t_tools tools;

    tools.envp = envp;
    if (argc != 1 || argv[1] != NULL)
    {
        printf("There shouldn't be any argument given to the program\n");
        exit(0);
    }
    ft_init_tools(&tools);
    minishell_loop(&tools);
    return (0);
}