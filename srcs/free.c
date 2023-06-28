/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:05:24 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/28 19:05:40 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    free_list(t_lexer *lexer_list)
{
    t_lexer *tmp;

    while (lexer_list)
    {
        tmp = lexer_list;
        lexer_list = lexer_list->next;
        free(tmp->token);
        free(tmp);
    }
}