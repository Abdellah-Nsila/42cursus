// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   parsing_path.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/13 15:41:17 by abnsila           #+#    #+#             */
// /*   Updated: 2025/01/14 19:02:44 by abnsila          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_parse_path(char **all_path, char *command)
{
	int		i;
	char	*temp;
	char	*path;
	char	*result;

	i = 0;
	result = NULL;
	while (all_path[i] && !result)
	{
		temp = ft_strjoin("/", command);
		if (!temp)
			break ;
		path = ft_strjoin(all_path[i], temp);
		free(temp);
		if (path && ft_check_access(path, X_OK))
			result = path;
		else
			free(path);
		i++;
	}
	ft_free_array(all_path);
	if (!result)
		result = ft_strdup(command);
	return (result);
}

char	*ft_get_path(char *command, char **envp)
{
	int		i;
	char	**all_path;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break;
		i++;
	}
	if (!envp[i])
		return (ft_strdup(command));
	all_path = ft_split(envp[i] + 5, ':');
	if (!all_path)
		return (ft_strdup(command));
	path = ft_parse_path(all_path, command);
	return (path);
}
