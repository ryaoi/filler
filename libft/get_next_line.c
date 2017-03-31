/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:44:47 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/30 21:43:58 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
 
int						get_line(char **line, t_line **list)
{
	int					i;

	i = 0;
	while ((*list)->stock[i] != '\0' && (*list)->stock[i] != '\n')
		i++;
	if ((*list)->stock[i] == '\n')
	{
		*line = ft_strsub((*list)->stock, 0, i);
		(*list)->stock = ft_strsub((*list)->stock, i + 1,
		ft_strlen((*list)->stock) - i + 1);
	}
	else if ((*list)->stock[i] == '\0')
	{
		if (i != 0)
			*line = ft_strsub((*list)->stock, 0, i);
		else
			*line = ft_strnew(0);
		(*list)->stock = ft_strnew(0);
		if (i == 0)
		{
			(*list)->fd = 0;
			return (0);
		}
	}
	return (1);
}

t_line					*find_fd(t_line **list, int fd)
{
	t_line				*ptr;

	ptr = *list;
	while (ptr != NULL)
	{
		if (ptr->fd == fd)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

t_line					*new_line(t_line **list, int fd, char *stock)
{
	t_line				*ptr;
	t_line				*new;

	ptr = *list;
	new = (t_line *)malloc(sizeof(t_line));
	new->stock = ft_strdup(stock);
	new->fd = fd;
	if (!ptr)
		*list = new;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
	new->next = NULL;
	return (new);
}

int						my_realloc(const int fd, t_line **list, t_line **ptr)
{
	char				*stock;
	char				*prev;
	char				buffer[BUFF_SIZE + 1];
	int					ret;

	ret = 1;
	stock = ft_strnew(1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret == -1)
			return (ret);
		buffer[ret] = '\0';
		prev = ft_strdup(stock);
		ft_strdel(&(stock));
		stock = ft_strjoin(prev, buffer);
		ft_strdel(&prev);
	}
	*ptr = new_line(list, fd, stock);
	ft_strdel(&(stock));
	return (ret);
}

int						get_next_line(const int fd, char **line)
{
	static t_line		*list = NULL;
	t_line				*ptr;
	int					ret;

	ret = 1;
	ptr = list;
	if (fd < 0 || (!(line)) || BUFF_SIZE < 1)
		return (-1);
	if (!(*line))
		*line = NULL;
	*line = ft_strnew(0);
	if (!(ptr = find_fd(&list, fd)))
		ret = my_realloc(fd, &list, &ptr);
	if (ret == -1)
		return (ret);
	return (get_line(line, &ptr));
}
*/

static void			add_chunk(char **line, char *buff, size_t size)
{
    char	*tmp;
    char	*ptr_tmp;
    
    if (*line == NULL)
        *line = ft_strnew(1);
    tmp = ft_strsub(buff, 0, size);
    ptr_tmp = *line;
    *line = ft_strjoin(*line, tmp);
    free(ptr_tmp);
    free(tmp);
}

static void			parse(const int fd, char **line, t_fd_buff *fd_buff)
{
    unsigned int begin_pos;
    
    begin_pos = fd_buff->pos;
    while (fd_buff->buff[fd_buff->pos] != '\n' && fd_buff->n != 0)
    {
        if (--(fd_buff->n) == 0)
        {
            add_chunk(line, fd_buff->buff + begin_pos,
                      fd_buff->pos - begin_pos + 1);
            fd_buff->pos = 0;
            begin_pos = fd_buff->pos;
            fd_buff->n = read(fd, fd_buff->buff, BUFF_SIZE);
        }
        else
            (fd_buff->pos)++;
    }
    if (fd_buff->n != 0)
    {
        add_chunk(line, fd_buff->buff + begin_pos, fd_buff->pos - begin_pos);
        --(fd_buff->n);
        ++(fd_buff->pos);
    }
}

static t_fd_buff	*find_fd_buff(t_list *lst, int fd)
{
    while (lst != NULL)
    {
        if (((t_fd_buff *)lst->content)->fd == fd)
            return (lst->content);
        lst = lst->next;
    }
    return (NULL);
}

static t_fd_buff	*select_fd_buff(t_list **lst, int fd)
{
    t_fd_buff	*new_fd_buff;
    t_fd_buff	*ptr;
    t_list		*new_lst;
    
    if ((ptr = find_fd_buff(*lst, fd)) != NULL)
        return (ptr);
    if ((new_fd_buff = (t_fd_buff *)malloc(sizeof(t_fd_buff))) == NULL)
        return (NULL);
    new_fd_buff->fd = fd;
    new_fd_buff->pos = 0;
    new_fd_buff->n = 0;
    new_fd_buff->buff = (char *)malloc(sizeof(char) * BUFF_SIZE);
    if (new_fd_buff->buff == NULL)
        return (NULL);
    if ((new_lst = ft_lstnew(new_fd_buff, sizeof(t_list))) == NULL)
        return (NULL);
    ft_lstadd(lst, new_lst);
    free(new_fd_buff);
    return ((*lst)->content);
}

int					get_next_line(const int fd, char **line)
{
    static t_list	*lst = NULL;
    t_fd_buff		*fd_buff;
    
    *line = NULL;
    fd_buff = select_fd_buff(&lst, fd);
    if (fd_buff == NULL)
        return (-1);
    if (fd_buff->n <= 0)
    {
        if ((fd_buff->n = read(fd, fd_buff->buff, BUFF_SIZE)) <= 0)
            return (fd_buff->n);
        else
            fd_buff->pos = 0;
    }
    parse(fd, line, fd_buff);
    return (1);
}
