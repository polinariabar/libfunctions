/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:00:38 by leweathe          #+#    #+#             */
/*   Updated: 2020/05/27 14:54:32 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_lstnew(int content)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->fd = content;
		tmp->content = ft_strdup("");
		tmp->next = NULL;
	}
	return (tmp);
}

int		reading_line(t_list *file, long long size, int fd)
{
	char		*tmp_stack;
	long long	ret;
	char		*buffer;

	buffer = (char *)malloc(sizeof(char) * size + 1);
	while ((ret = read(fd, buffer, size)) > 0)
	{
		buffer[ret] = '\0';
		if (file->content)
		{
			if (!(tmp_stack = ft_strdup(file->content)))
				return (-1);
			free(file->content);
			file->content = NULL;
			if (!(file->content = ft_strjoin(tmp_stack, buffer)))
				return (-1);
			free(tmp_stack);
		}
		else if (!(file->content = ft_strdup(buffer)))
			return (-1);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (ret);
}

int		save_line(char **line, t_list *file, int i)
{
	char	*tmp_stack;

	if (!(*line = ft_substr(file->content, 0, i)))
		return (-1);
	if (!(tmp_stack = ft_strdup(file->content)))
		return (-1);
	free(file->content);
	if (!(file->content = ft_strdup(tmp_stack + i + 1)))
		return (-1);
	free(tmp_stack);
	return (1);
}

t_list	*list(t_list **lst, int fd)
{
	t_list	*tmp;

	if (!*lst)
		*lst = ft_lstnew(fd);
	tmp = *lst;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = ft_lstnew(fd);
		tmp = tmp->next;
	}
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	long long		i;
	static t_list	*lst;
	t_list			*tmp;
	long long		ret;

	i = 0;
	tmp = list(&lst, fd);
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (ft_strchr(tmp->content, '\n') == NULL)
		if ((ret = reading_line(tmp, BUFFER_SIZE, fd)) <= 0)
		{
			if (ret == 0 && tmp->content == NULL)
				*line = ft_strdup("\0");
			if ((ret == 0 && tmp->content == NULL) || ret == -1)
				return (ret);
		}
	while (tmp->content[i] != '\n' && tmp->content[i] != '\0')
		i++;
	if (tmp->content[i] == '\n')
		return (save_line(line, tmp, i));
	*line = ft_strdup(tmp->content);
	free(tmp->content);
	tmp->content = NULL;
	return (*line ? 0 : -1);
}
