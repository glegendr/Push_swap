/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 00:32:25 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/13 19:02:02 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_error_del(t_vec *va, t_vec *vb, t_vec *vp, char **argv)
{
	int i;

	i = 0;
	write(2, "Error\n", 6);
	if (v_size(va) != 0)
		v_del(va);
	if (v_size(vp) != 0)
		v_del(vp);
	if (v_size(vb) != 0)
		v_del(vb);
	while (argv[i])
		free(argv[i++]);
	free(argv[i]);
	exit(1);
}

int		ft_check_argv(int argc, char **argv, t_vec *va, t_vec *vb)
{
	int flag;

	flag = 0;
	if (argc <= 1)
		ft_error_del(va, vb, va, argv);
	if (!ft_strcmp(argv[1], "-v") || !ft_strcmp(argv[1], "-c"))
		flag = 1;
	if (argc <= 2 && flag == 1)
		ft_error_del(va, vb, va, argv);
	if ((!ft_strcmp(argv[2], "-v") || !ft_strcmp(argv[2], "-c")) && flag == 1)
		flag = 2;
	if (argc <= 3 && flag > 0)
		ft_error_del(va, vb, va, argv);
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
		while (argv[argc - y][i++])
			if ((argv[argc - y][i - 1] > '9' || argv[argc - y][i - 1] < '0') &&
					argv[argc - y][i - 1] != '-' &&
					argv[argc - y][i - 1] != '+')
				ft_error_del(va, vb, va, argv);
		i = 0;
		tab[y - 1] = ft_atoi(argv[argc - y]);
		while (i < y - 1)
			if (tab[i++] == ft_atoi(argv[argc - y]))
				ft_error_del(va, vb, va, argv);
		v_push_int(va, ft_atoi(argv[argc - y]));
	}
	free(tab);
}

void	ft_del_vec(t_vec *vp, t_vec *va, t_vec *vb, char **argv)
{
	int i;

	i = 0;
	v_del(vp);
	v_del(va);
	v_del(vb);
	while (argv[i])
	{
		free(argv[i]);
		++i;
	}
	free(argv);
}

int		main(int argc, char **argv)
{
	t_vec	va;
	t_vec	vb;
	t_vec	vp;
	int		flag;

	argv = carve_argv(&argc, argv);
	if (argc <= 2)
		ft_error();
	check_int(argc, argv);
	va = v_new(sizeof(int));
	vb = v_new(sizeof(int));
	flag = ft_check_argv(argc, argv, &va, &vb);
	ft_check(&va, &vb, argv, argc);
	vp = v_new(sizeof(char));
	if (v_size(&va) >= 11)
		ft_algo(&va, &vb, &vp, flag);
	else if (v_size(&va) > 5)
		algo_under_ten(&va, &vb, &vp, flag);
	else
		algo_under_five(&va, &vb, &vp, flag);
	v_print(&vp, 1);
	ft_del_vec(&va, &vb, &vp, argv);
	return (0);
}
