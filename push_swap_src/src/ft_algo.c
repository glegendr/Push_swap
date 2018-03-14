/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 05:06:45 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/14 22:09:36 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int			nbef(t_vec *v, int next, int ret, int i)
{
	int min;
	int check;

	min = -2147483648;
	check = 0;
	while (i++ < v_size(v))
		if (*(int *)v_get(v, i - 1) > min && *(int *)v_get(v, i - 1) < next)
		{
			ret = v_size(v) - (i - 1);
			min = *(int *)v_get(v, i - 1);
			check = 1;
		}
	i = 0;
	if (check == 0)
		while (i++ < v_size(v))
			if (*(int *)v_get(v, i - 1) > min)
			{
				ret = v_size(v) - (i - 1);
				min = *(int *)v_get(v, i - 1);
				check = 1;
			}
	if (ret > v_size(v))
		return (1);
	return (ret);
}

int			nbmin(t_vec *v)
{
	int min;
	int i;

	i = 0;
	min = 2147483647;
	while (i < v_size(v))
	{
		if (*(int *)v_get(v, i) < min)
			min = *(int *)v_get(v, i);
		++i;
	}
	return (min);
}

int			nbpos(t_vec *v, int nb)
{
	int pos;

	pos = 0;
	while (pos < v_size(v))
	{
		if (*(int *)v_get(v, pos) == nb)
			return (v_size(v) - pos);
		++pos;
	}
	return (v_size(v));
}

int			nextnb_inquart(t_vec *v, int quart)
{
	int i;

	i = 1;
	while (i < v_size(v))
	{
		if (*(int *)v_get(v, v_size(v) - i) <= quart)
			return (*(int *)v_get(v, v_size(v) - i));
		++i;
	}
	return (0);
}

void		ft_algo(t_vec *va, t_vec *vb, t_vec *vp, int flag)
{
	int *quart;
	int i;
	int *fq;
	int end;

	if (ft_sorted(va, vb))
		return ;
	end = 13;
	if (v_size(va) < 150)
		end = 7;
	fq = (int *)malloc(sizeof(int) * 2);
	fq[0] = flag;
	quart = ft_quartile(va);
	i = 1;
	while (i <= end)
	{
		fq[1] = quart[i];
		sort_part_i(va, vb, vp, fq);
		++i;
	}
	algo_under_five(va, vb, vp, flag);
	free(fq);
	free(quart);
}
