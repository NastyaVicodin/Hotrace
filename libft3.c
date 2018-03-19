/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrupski <akrupski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 12:19:36 by akrupski          #+#    #+#             */
/*   Updated: 2017/12/03 18:33:15 by akrupski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		s1++;
		s2++;
	}
	return (0);
}

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		return (new);
	}
	new->content = (void *)malloc(content_size);
	if (!new->content)
		return (NULL);
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	return (new);
}

void	*ft_memalloc(size_t size)
{
	unsigned char *str;

	str = (unsigned char *)malloc(size);
	if (!str)
		return (NULL);
	while (size != 0)
		str[size--] = 0;
	str[size] = 0;
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*new;
	const unsigned char	*old;

	new = dst;
	old = src;
	while (n != 0)
	{
		*(new++) = *(old++);
		n--;
	}
	return (dst);
}
