/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_reader_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:52:30 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/28 23:20:44 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_lexer	*ft_lexernew(char *str, int token)
{
	t_lexer		*new_element;

	new_element = (t_lexer *)malloc(sizeof(t_lexer));
	if (!new_element)
		return (0);
	new_element->type = token;
    if (token == 1)
        new_element->content = ft_strdup("|");
    else if (token == 2)
        new_element->content = ft_strdup(">>");
    else if (token == 3)
        new_element->content = ft_strdup("<<");
    else if (token == 4)
        new_element->content = ft_strdup(">");
    else if (token == 5)
        new_element->content = ft_strdup("<");
    else if (token == 6)
        new_element->content = ft_strdup(str);
	new_element->next = NULL;
	return (new_element);
}

void	ft_lexeradd_back(t_lexer **lst, t_lexer *new)
{
	t_lexer	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}


int	handle_quotes(int i, char *str, char del)
{
	int	j;

	j = 0;
	if (str[i + j] == del)
	{
		j++;
		while (str[i + j] != del && str[i + j])
			j++;
		j++;
	}
	return (j);
}

int	check_token(char *c)
{
    if (c[0] == '|')
        return (1);
    else if (c[0] == '>' && c[1] == '>')
        return (2);
    else if (c[0] == '<' && c[1] == '<')
        return (3);
    else if (c[0] == '>' && c[1] != '>')
        return (4);
    else if (c[0] == '<' && c[1] != '<')
        return (5);
	return (0);
}

int	handle_token(char *str, int i, t_lexer **lexer_list)
{
	int token;

	token = check_token(&str[i]);
	if (token == 2 || token == 3)
	{
		if (!add_node(NULL, token, lexer_list))
			return (-1);
		return (2);
	}
	else if (token)
	{
		if (!add_node(NULL, token, lexer_list))
			return (-1);
		return (1);
	}	
	return (0);
}