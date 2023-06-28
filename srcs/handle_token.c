/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:57:00 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/28 18:56:31 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
This file enable to put all the tokens in tools->lexer_list.
The tokens are: |, >, <, >>, <<, ;
They are put in the same order as they are in the args.
*/

void	count_pipes(t_lexer *lexer_list, t_tools *tools)
{
	t_lexer	*tmp;

	tmp = lexer_list;
	tools->pipes = 0;
	while (tmp)
	{
		if (ft_strncmp(tmp->token,"|", 1) == 0)
			tools->pipes++;
		tmp = tmp->next;
	}
}

void ft_add_lexer(t_tools *tools, int coef)
{
    t_lexer *lexer;
    t_lexer *new;

    lexer = tools->lexer_list;
    while (lexer->next != NULL)
        lexer = lexer->next;
    new = malloc(sizeof(t_lexer));
    if (!new)
        exit(0);
    if (coef == 1)
        new->token = ft_strdup("|");
    else if (coef == 2)
        new->token = ft_strdup(">");
    else if (coef == 3)
        new->token = ft_strdup("<");
    else if (coef == 4)
        new->token = ft_strdup(">>");
    else if (coef == 5)
        new->token = ft_strdup("<<");
    else if (coef == 6)
        new->token = ft_strdup(";");
    new->next = NULL;
    lexer->next = new;
}

void ft_handle_token(t_tools *tools, int *i)
{
    if ((tools->args[*i] == '|')
        || (tools->args[*i] == '>' && tools->args[*i + 1] != '>')
        || (tools->args[*i] == '<' && tools->args[*i + 1] != '<'))
    {
        if (tools->args[*i] == '|')
            ft_add_lexer(tools, 1);
        if (tools->args[*i] == '>')
            ft_add_lexer(tools, 2);
        if (tools->args[*i] == '<')
            ft_add_lexer(tools, 3);
        *i = *i + 1;
    }
    if ((tools->args[*i] == '>' && tools->args[*i + 1] == '>')
        || (tools->args[*i] == '<' && tools->args[*i + 1] == '<'))
    {
        if (tools->args[*i] == '>')
            ft_add_lexer(tools, 4);
        if (tools->args[*i] == '<')
            ft_add_lexer(tools, 5);
        *i = *i + 2;
    }
}

int ft_token_reader(t_tools *tools)
{
    int i;

    i = 0;
    while (tools->args[i])
    {
        if ((tools->args[i] == '<') || (tools->args[i] == '|')
            || (tools->args[i] == '>'))
            ft_handle_token(tools, &i);
        i++;
    }
    ft_add_lexer(tools, 6);
    return (0);
}