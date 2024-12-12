
#include "get_next_line.h"

char	*ft_clean(char **static_var)
{
	free(*static_var);
	*static_var = NULL;
	return (NULL);
}

char	*ft_append_buff(char **static_var, char *buff, ssize_t rb)
{
	char	*new_static_var;
	int		len;

	if (*static_var)
		len = ft_strlen(*static_var);
	else
		len = 0;
	new_static_var = (char *)malloc((len + rb + 1) * sizeof(char));
	if (!new_static_var)
		return (ft_clean(static_var));
	if (static_var)
	{
		ft_strlcpy(new_static_var, *static_var, len + 1);
		ft_clean(static_var);
	}
	ft_strlcat(new_static_var, buff, len + rb + 1);
	return (new_static_var);
}

char	*ft_get_remaining(char **static_var, char *buff, char *end_line)
{
	char	*new_static_var;
	size_t	remaining_len;

	remaining_len = ft_strlen(end_line + 1);
	new_static_var = (char *)malloc((remaining_len + 1) * sizeof(char));
	if (!new_static_var)
		return (ft_clean(static_var));
	ft_strlcpy(new_static_var, end_line + 1, remaining_len + 1);
	ft_clean(static_var);
	return (new_static_var);
}

char	*ft_get_line(char *static_var, char *end_line)
{
	size_t	len;
	char	*line;

	if (!static_var || !end_line)
		return (NULL);
	len = (end_line - static_var) + 1;
	line = (char *)malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, static_var, len + 1);
	return (line);
}

char	*ft_process_read_content(char **static_var, char *buff, char *end_line)
{
	char	*line;

	line = ft_get_line(*static_var, end_line);
	*static_var = ft_get_remaining(static_var, buff, end_line);
	if (!line)
		return (ft_clean(static_var));
	free(buff);
	return (line);
}

char *ft_handle_end_of_read(char **static_var, char *buff, ssize_t rb)
{
	char *end_line;
	char *line;

	free(buff);
	if (!static_var || !*static_var)
		return (ft_clean(static_var));
	end_line = ft_strchr(*static_var, '\n');
	if (end_line)
		return (ft_process_read_content(static_var, NULL, end_line));
	if (rb == 0 && *static_var && **static_var)
	{
		line = ft_strdup(*static_var);
		ft_clean(static_var);
		return (line);
	}
	return (ft_clean(static_var));
}

char	*get_next_line(int fd)
{
	static char	*static_var;
	ssize_t		rb;
	char		*buff;
	char		*end_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while ((rb = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rb] = '\0';
		static_var = ft_append_buff(&static_var, buff, rb);
		if (!static_var)
		{
			free(buff);
			return (NULL);
		}
		end_line = ft_strchr(static_var, '\n');
		if (end_line)
		{
			free(buff);
			return (ft_get_line(&static_var, end_line));
		}
	}
	return (ft_handle_end_of_read(&static_var, buff, rb));
}