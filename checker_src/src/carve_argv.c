/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carve_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:19:09 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/21 23:19:47 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void		ft_error_void(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void		check_int(int argc, char **argv)
{
	long long int i;
	int y;

	y = 1;
	while (y < argc)
	{
		i = ft_atolli(argv[y]);
		if (i > 2147483647 || i < -2147483648)
			ft_error_void();
		++y;
	}
}

char	**tab_join(char **tab, char *s, int i)
{
	char **tmp;

	if (tab == NULL)
	{
		tmp = (char **)malloc(sizeof(char *) * 2);
		tmp[0] = (char *)malloc(sizeof(char) * ft_strlen(s));
		ft_memcpy(tmp[0], s, ft_strlen(s));
		tmp[1] = NULL;
		return (tmp);
	}
	while (tab[i++]);
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tab[i])
	{
		tmp[i] = (char *)malloc(sizeof(char) * ft_strlen(tab[i]));
		ft_memcpy(tmp[i], tab[i], ft_strlen(tab[i]));
		++i;
	}
	tmp[i + 1] = NULL;
	tmp[i] = (char *)malloc(sizeof(char) * ft_strlen(s));
	ft_memcpy(tmp[i], s, ft_strlen(s));
	free(tab);
	return (tmp);
}

char	**carve_argv(int *argc, char **argv)
{
	int i;
	int y;
	char **tab;
	char **final;

	final = NULL;
	i = 0;
	while (argv[i])
	{
		y = 0;
		tab = ft_strsplit(argv[i], ' ');
		while (tab[y])
		{
			final = tab_join(final, tab[y], 0);
			++y;
		}
		free(tab);
		++i;
	}
	i = 0;
	while (final[++i]);
	*argc = i;
	return (final);
}
