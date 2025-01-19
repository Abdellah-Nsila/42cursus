/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:41:19 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/19 12:50:44 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_bool	ft_check_access(char *file, int permission) //  permission: R_OK  W_OK  X_OK
{
	if (access(file, permission) == -1)
		return (false);
	return (true);
}

t_bool	ft_parse_infile(t_pipex *pipex, char *infile)
{
	int fd;

	if (ft_check_access(infile, R_OK))
	{
		fd = open(infile, O_RDONLY);
		if (fd < 0)
			return (false);
		// close(fd);
		pipex->infile = ft_strdup(infile);
		pipex->infile_fd = fd;
	}
	else
	{
		pipex->is_invalid_infile = true;	
		return (false);
	}
	return (true);
}

// TODO you must chek the permission of each file ( already XD (: )) , and take descision
// TODO exit, print error, clean ...
t_bool	ft_parse_outfile(t_pipex *pipex, char *outfile)
{
	int flags;
	int fd;

	if (pipex->here_doc)
		flags = (O_WRONLY | O_CREAT | O_APPEND);
	else
		flags = (O_WRONLY | O_CREAT | O_TRUNC);
	fd = open(outfile, flags);
	if (fd < 0)
		return (false);
	// close(fd);
	pipex->outfile = ft_strdup(outfile);
	pipex->outfile_fd = fd;
	return (true);
}
