/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 11:22:20 by kanlee            #+#    #+#             */
/*   Updated: 2020/07/20 17:42:05 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void				ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ;
}

void				free_prev(t_stock_str *target, int idx)
{
	int i;

	i = 0;
	while (i < idx)
	{
		free(target[i].copy);
		i++;
	}
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*ret;

	if (ac < 0)
		return (void *)(0);
	ret = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!ret)
		return (void *)(0);
	ret[ac].str = 0;
	i = -1;
	while (++i < ac)
	{
		ret[i].size = ft_strlen(av[i]);
		ret[i].str = av[i];
		ret[i].copy = (char *)malloc((ret[i].size + 1) * sizeof(char));
		if (!(ret[i].copy))
		{
			free_prev(ret, i);
			free(ret);
			return (void *)(0);
		}
		else
			ft_strcpy(ret[i].copy, av[i]);
	}
	return (ret);
}
