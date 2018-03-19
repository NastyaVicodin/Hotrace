/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrupski <akrupski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:51:39 by akrupski          #+#    #+#             */
/*   Updated: 2017/12/03 13:55:42 by akrupski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_hash	*create_new_section(t_hash *hash, char *key, char *value)
{
	t_hash *next_hash;

	if (hash)
	{
		if (ft_strcmp(hash->key, key) > 0)
			hash->left = create_new_section(hash->left, key, value);
		else if (ft_strcmp(hash->key, key) < 0)
			hash->right = create_new_section(hash->right, key, value);
		else
		{
			free(hash->value);
			hash->value = ft_strdup(value);
		}
		return (hash);
	}
	else
	{
		next_hash = (t_hash *)malloc(sizeof(t_hash));
		next_hash->value = ft_strdup(value);
		next_hash->key = ft_strdup(key);
		next_hash->left = NULL;
		next_hash->right = NULL;
	}
	return (next_hash);
}

t_hash	*read_hash(void)
{
	char	*key;
	char	*value;
	t_hash	*hash;
	int		i;

	i = 0;
	hash = NULL;
	while (get_next_line(0, &key) > 0)
	{
		if (!ft_strlen(key) && i != 0)
			return (hash);
		i = 1;
		get_next_line(0, &value);
		hash = create_new_section(hash, key, value);
		free(key);
		free(value);
	}
	return (hash);
}

void	search_hash(t_hash *hash, char *key)
{
	if (hash == NULL)
	{
		write(1, key, ft_strlen(key));
		write(1, " Not found.\n", 13);
	}
	else if (ft_strcmp(hash->key, key) > 0)
		search_hash(hash->left, key);
	else if (ft_strcmp(hash->key, key) < 0)
		search_hash(hash->right, key);
	else
	{
		write(1, hash->value, ft_strlen(hash->value));
		write(1, "\n", 1);
	}
}

int		main(void)
{
	t_hash	*hash;
	char	*str;

	hash = read_hash();
	while (get_next_line(0, &str))
		search_hash(hash, str);
	return (0);
}
