/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrupski <akrupski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:51:33 by akrupski          #+#    #+#             */
/*   Updated: 2017/12/03 18:25:32 by akrupski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# define BUFF_SIZE 4096
# define RED -1
# define BLACK 1
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct	s_hash
{
	char			*key;
	char			*value;
	int				color;
	struct s_hash	*parent;
	struct s_hash	*left;
	struct s_hash	*right;
}				t_hash;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_gnl
{
	char		*buf;
	int			count;
	int			i;
	int			nl;
	int			fd;
}				t_gnl;

int				get_next_line(const int fd, char **line);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_memdel(void **ap);
char			*ft_strchr(const char *s, int c);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(char const *s);
char			*ft_strmerge(char *a, char *b);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			*ft_memalloc(size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t n);

#endif
