/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:13:19 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/28 23:13:18 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../libft/includes/libft.h"

typedef struct s_tools
{
	char					*args;
	char					**envp;
	struct s_lexer					*lexer_list;
	int						pipes;
}	t_tools;

typedef struct s_lexer
{
	char					*content;
	int						type;
	struct s_lexer			*next;
	
}	t_lexer;

// free.c
void    free_list(t_lexer **lexer_list);

// error.c
int	ft_error(int error);

// check_quotes.c
int	check_quotes(char *line);
int	find_matching_quote(char *line, int i, int *num_del, int del);

// handle_token.c
//void ft_handle_token(t_tools *tools, int *i);
//void ft_add_lexer(t_tools *tools, int coef);
//t_lexer *ft_lstlast(t_lexer *lst);
//int ft_token_reader(t_tools *tools);

// ft_token_reader_utils.c
int	handle_token(char *str, int i, t_lexer **lexer_list);
int	check_token(char *c);
int	handle_quotes(int i, char *str, char del);
void	ft_lexeradd_back(t_lexer **lst, t_lexer *new);
t_lexer	*ft_lexernew(char *str, int token);


// ft_token_reader.c
int	ft_token_reader(t_tools *tools);
int	read_words(int i, char *str, t_lexer **lexer_list);
int	add_node(char *str, int token, t_lexer **lexer_list);
int	skip_spaces(char *str, int i);
int	is_whitespace(char c);

// minishell_loop.c
int minishell_loop(t_tools *tools);
int ft_reset(t_tools *tools);

// main.c
int main(int argc, char **argv, char **envp);
void    ft_init_tools(t_tools *tools);

#endif