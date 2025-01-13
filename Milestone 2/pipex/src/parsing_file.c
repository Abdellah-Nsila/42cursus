/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:41:19 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/13 16:26:20 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_check_access(char *file, int permission) //  permission: R_OK  W_OK  X_OK
{
	if (access(file, permission) == -1)
		return (0);
	return (1);
}

int	ft_parse_infile(t_pipex *pipex, char *infile)
{
	int fd;

	if (ft_check_access(infile, R_OK))
	{
		pipex->infile = ft_strdup(infile);
	}
	fd = open(infile, O_RDONLY);
	if (fd < 0)
		return (0);
	// close(fd);
	pipex->infile = ft_strdup(infile);
	pipex->infile_fd = fd;
	return (1);
}

int	ft_parse_outfile(t_pipex *pipex, char *outfile, int here_doc)
{
	int flags;
	int fd;

	if (here_doc)
		flags = (O_WRONLY | O_CREAT | O_APPEND);
	else
		flags = (O_WRONLY | O_CREAT | O_TRUNC);
	fd = open(outfile, flags);
	if (fd < 0)
		return (0);
	// close(fd);
	pipex->outfile = ft_strdup(outfile);
	pipex->outfile_fd = fd;
	return (1);
}