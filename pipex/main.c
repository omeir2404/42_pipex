/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:02:18 by oharoon           #+#    #+#             */
/*   Updated: 2023/06/06 19:26:04 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, int r_or_w)
{
	int	ret;

	if (r_or_w == 0)
		ret = open(file, O_RDONLY, 0777);
	if (r_or_w == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (ret < 0)
		exit(0);
	return (ret);
}

void	free_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	exec(char *comand, char **env)
{
	char	**split_comand;
	char	*path;

	split_comand = ft_split(comand, ' ');
	path = get_path(split_comand[0], env);
	if (execve(path, split_comand, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(split_comand[0], 2);
		free_matrix(split_comand);
		exit(0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc != 5)
		exit(0);
	if (pipe(pipe_fd) < 0)
	{
		printf("pipe error");
		return (0);
	}
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
		child_handle(argv, pipe_fd, envp);
	wait(NULL);
	parent(argv, pipe_fd, envp);
}
