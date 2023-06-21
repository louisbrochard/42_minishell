/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:26:26 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/21 12:26:43 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char **argv, char **envp)
{
    t_tools tools;

    tools.envp = envp;
    if (argc != 1 || argv[1] != NULL)
    {
        printf("There shouldn't be any argument given to the program\n");
        exit(0);
    }
    minishell_loop(&tools);
    return (0);
}