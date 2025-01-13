/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:45:07 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/13 18:34:45 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>

# include "../Libft/includes/libft.h"

// Begin && End indexs range of Commands inside the argv array
typedef struct	s_range
{
	int	start;
	int	end;
}	t_range;


// Pipex struct
typedef struct	s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	t_bool	here_doc;
	char	*limiter;
	t_bool	is_invalid_infile;
	char	*infile;
	char	*outfile;
	char	**cmd_paths;
	char	***cmd_args;
	char	**cmd_envs;
	int		cmd_count;
}	t_pipex;

// Clean up functions
void	ft_clean_pipex(t_pipex *pipex);
void	ft_free_count_array(char **arr, int count);
void	ft_freearray(char **arr);
void	ft_free_2d_array(t_pipex *pipex);
void	ft_free_2d_count_array(t_pipex *pipex, int count);


// Parse files
t_bool		ft_check_access(char *file, int permission);
t_bool		ft_parse_infile(t_pipex *pipex, char *infile);
t_bool		ft_parse_outfile(t_pipex *pipex, char *outfile, int here_doc);

// Parse Path
char		*ft_parse_default_path(char *command);
char		*ft_parse_path(char	**all_path, char *command);
char		*ft_get_path(char *command, char **envp);

// Parse Arguments
void		ft_init_pipex(t_pipex *pipex, char **envp);
char		**ft_get_cmd_arg(char **argv, int index);
t_bool		ft_parse_cmd_args(t_pipex *pipex, char **argv, t_range range);
t_bool		ft_parse_cmd_paths(t_pipex *pipex, t_range range, char **envp);


// Debugging
void	ft_display_pipex(const t_pipex *pipex);

#endif 