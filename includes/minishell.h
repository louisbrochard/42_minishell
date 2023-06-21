/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:13:19 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/21 12:43:52 by louisbrocha      ###   ########.fr       */
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
}	t_tools;

// minishell_loop.c
int minishell_loop(t_tools *tools);
int ft_reset(t_tools *tools);

// main.c
int main(int argc, char **argv, char **envp);

#endif