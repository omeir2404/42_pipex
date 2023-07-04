/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:07:58 by oharoon           #+#    #+#             */
/*   Updated: 2023/06/06 19:28:55 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*my_getenv(const char *name, char **env)
{
	int		i;
	size_t	name_len;

	i = 0;
	name_len = ft_strlen(name);
	while (env[i] != NULL)
	{
		if ((ft_strncmp(env[i], name, name_len) == 0)
			&& (env[i][name_len] == '='))
			return (env[i] + name_len + 1);
		i++;
	}
	return (NULL);
}

char	*get_path(char *comand, char **env)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**split_comand;

	i = -1;
	allpath = ft_split(my_getenv("PATH", env), ':');
	split_comand = ft_split(comand, ' ');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, split_comand[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free_matrix(split_comand);
			return (exec);
		}
		free(exec);
	}
	free_matrix(allpath);
	free_matrix(split_comand);
	return (comand);
}
