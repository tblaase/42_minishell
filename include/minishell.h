/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:29:02 by tschmitt          #+#    #+#             */
/*   Updated: 2021/11/09 18:08:37 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <errno.h>
# include <dirent.h>
# include <stdbool.h>

typedef struct s_environment
{
	char	**envp;
	char	**env_var;
}			t_environment;

/* INBUILD */
int		echo(char **args);
char	**export(char **argv, char **env_var);
char	**unset(char **argv, char **env_var);
int		env(char **envp);
int		pwd(void);
int		cd(char **argv, t_environment *environment);

#endif
