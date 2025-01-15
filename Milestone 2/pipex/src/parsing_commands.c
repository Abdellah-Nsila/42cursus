/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:59:19 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/15 16:22:56 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_bool	ft_init_cmd_struct_arr(t_pipex *pipex)
{
	int	i;

	if (!pipex)
		return (false);
	i = 0;
	pipex->cmd_args = (char ***) malloc(sizeof(char **) * (pipex->cmd_count + 1));
	if (pipex->cmd_args)
	{
		while (i <= pipex->cmd_count)
			pipex->cmd_args[i++] = NULL;
	}
	i = 0;
	pipex->cmd_paths = (char **) malloc(sizeof(char *) * (pipex->cmd_count + 1));
	if (pipex->cmd_paths)
	{	
		while (i <= pipex->cmd_count)
			pipex->cmd_paths[i++] = NULL;
	}
	return (true);
}

char	**ft_get_cmd_arg(char **argv, int index)
{
	char	**cmd_args;

	cmd_args = ft_split(argv[index], ' ');
	if (!cmd_args)
		return (NULL);
	return (cmd_args);
	
}

t_bool	ft_parse_cmd_args(t_pipex *pipex, char **argv, t_range range)
{
	int		i;
	char	**cmd_args;

	i = 0;
	pipex->cmd_count = range.end - range.start;
	if (ft_init_cmd_struct_arr(pipex) == false)
		return (false);
	i = 0;
	while (range.start < range.end)
	{
		cmd_args = ft_get_cmd_arg(argv, range.start);
		if (!cmd_args)
			return (false);
		pipex->cmd_args[i] = cmd_args;
		i++;
		range.start++;
	}
	pipex->cmd_args[i] = NULL;
	return (true);
}

t_bool	ft_parse_cmd_paths(t_pipex *pipex, t_range range, char **envp)
{
	int		i;
	char	*path;

	if (!pipex)
		return (false);
	i = 0;
	while (range.start < range.end && i < pipex->cmd_count)
	{
		if (pipex->cmd_args[i] && pipex->cmd_args[i][0])
		{
			path = ft_get_path(pipex->cmd_args[i][0], envp);
			if (path)
				pipex->cmd_paths[i] = path;
			else
				pipex->cmd_paths[i] = ft_strdup("");  // Empty string for failed paths
		}
		else
			pipex->cmd_paths[i] = ft_strdup("");  // Empty string for NULL commands	
		i++;
		range.start++;
	}
	pipex->cmd_paths[i] = NULL;
	return (true);
}

t_bool	ft_check_args(t_pipex *pipex, int argc, char **argv, char **envp)
{
	t_range	range;

	if (!pipex || (ft_check_parse_format(argc, argv) == false))
		return (false);
	range.end = argc - 1;
	range.start = 2;
	return (
		ft_parse_cmd_args(pipex, argv, range) &&
		ft_parse_cmd_paths(pipex, range, envp) &&
		ft_parse_infile(pipex, argv[1]) &&
		ft_parse_outfile(pipex, argv[argc - 1], 1));
}
