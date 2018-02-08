/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 00:32:25 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/08 02:12:35 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "vector.h"

void	ft_error(t_vec *va, t_vec *vb, t_vec *vp)
{
	write(2, "Error\n", 6);
	if (v_size(va) != 0)
		v_del(va);
	if (v_size(vp) != 0)
		v_del(vp);
	if (v_size(vb) != 0)
		v_del(vb);
	exit(1);
}

int		ft_check_argv(int argc, char **argv, t_vec *va, t_vec *vb)
{
	int flag;

	flag = 0;
	if (argc <= 1)
		ft_error(va, vb, va);
	flag = 0;
	if (!ft_strcmp(argv[1], "-v") || !ft_strcmp(argv[1], "-c"))
		flag = 1;
	if (argc <= 2 && flag == 1)
		ft_error(va, vb, va);
	if ((!ft_strcmp(argv[2], "-v") || !ft_strcmp(argv[2], "-c")) && flag == 1)
		flag = 2;
	if (argc <= 3 && flag > 0)
		ft_error(va, vb, va);
	if (flag == 1 && !ft_strcmp(argv[1], "-c"))
		flag = 0;
	return (flag);
}

void	ft_check(t_vec *va, t_vec *vb, char **argv, int argc)
{
	int i;
	int *tab;
	int y;
	int flag;

	flag = ft_check_argv(argc, argv, va, vb) + 1;
	y = 0;
	tab = (int *)malloc(sizeof(int) * argc - 1);
	while (argc - y++ > flag)
	{
		i = 0;
		while (argv[argc - y][i])
			if (argv[argc - y][i] > '9' || argv[argc - y][i++] < '0')
				ft_error(va, vb, va);
		i = 0;
		tab[y - 1] = ft_atoi(argv[argc - y]);
		while (i < y - 1)
			if (tab[i++] == ft_atoi(argv[argc - y]))
				ft_error(va, vb, va);
		v_push(va, argv[argc - y]);
	}
	free(tab);
}

void	ft_del_vec(t_vec *vp, t_vec *va, t_vec *vb)
{
	v_del(vp);
	v_del(va);
	v_del(vb);
}

int		main(int argc, char **argv)
{
	char	*s;
	t_vec	va;
	t_vec	vb;
	t_vec	vp;
	int		flag;
	int		o = 0;

	va = v_new(sizeof(char *));
	vb = v_new(sizeof(char *));
	flag = ft_check_argv(argc, argv, &va, &vb);
	ft_check(&va, &vb, argv, argc);
	vp = v_new(sizeof(char));
	//ft_divide(&va, &vb, &vp, flag, &o);
//	printf("%s, %s && %s, %s, %s\n", v_get(&va, 0), v_get(&va, 1), v_get(&vb, 0), v_get(&vb, 1), v_get(&vb, 2));
//	v_print(&vp, 1);
	ft_algo(&va, &vb, &vp, flag, &o);
	printf("\n argc=%i, nb de combi=%i, sorted ?=%i\n", argc, o, ft_va_issorted(&va));
	ft_del_vec(&va, &vb, &vp);
	return (0);
}
