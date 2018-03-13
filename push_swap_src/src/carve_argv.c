/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carve_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:19:09 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/13 18:51:20 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void		ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void		check_int(int argc, char **argv)
{
	long long int	i;
	int				y;

	y = 1;
	while (y < argc)
	{
		i = ft_atolli(argv[y]);
		if (i > 2147483647 || i < -2147483648)
			ft_error();
		++y;
	}
}

char		**tab_join(char **tab, char *s)
{
	int		i;
	char	**tmp;

	i = 0;
	if (tab == NULL)
	{
		tab = (char **)malloc(sizeof(char *) * 2);
		tab[0] = ft_strdup(s);
		tab[1] = NULL;
		return (tab);
	}
	while (tab[i])
		++i;
	tmp = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (tab[i++])
		tmp[i - 1] = ft_strdup(tab[i - 1]);
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tmp[i] = ft_strdup(s);
	tmp[i + 1] = NULL;
	return (tmp);
}

char		**carve_argv(int *argc, char **argv)
{
	int		i;
	int		y;
	char	**tab;
	char	**final;

	final = NULL;
	i = 0;
	while (argv[i])
	{
		y = 0;
		tab = ft_strsplit(argv[i], ' ');
		while (tab[y])
		{
			final = tab_join(final, tab[y]);
			free(tab[y]);
			++y;
		}
		free(tab);
		++i;
	}
	i = 0;
	while (final[i])
		++i;
	*argc = i;
	return (final);
}
