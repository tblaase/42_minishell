/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interprete_vars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toni <toni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:13:27 by tschmitt          #+#    #+#             */
/*   Updated: 2021/12/04 23:01:42 by toni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.h"
#include "minishell.h"
#include "parser_utils.h"

// char	*get_env_var_value(char **env_var, char *var);

/**
 * @brief  Interprets enviroment variables of current lexer token
 * @note   Frees current lex_tok if necessary
 * @param  *lex_tok: Current lexer token
 * @retval Returns interpreted lexer token
 */
char	*interprete_vars(char *lex_tok)
{
	char	*interpreted_token;
	char	*var;

	interpreted_token = lex_tok;
	if (!ft_strchr(lex_tok, '\'') && ft_strlen(lex_tok) > 1 \
	&& lex_tok[0] == '$')
	{
		var = ft_substr(lex_tok, 1, ft_strlen(lex_tok));
		if (var == NULL)
			return (NULL);
		// interpreted_token = get_env_var_value(get_envp(), var);
		interpreted_token = ft_strdup(getenv(var));
		free(var);
		free(lex_tok);
		if (interpreted_token == NULL)
			return (ft_strdup(" "));
	}
	return (interpreted_token);
}
