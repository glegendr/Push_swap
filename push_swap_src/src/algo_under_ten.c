/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_under_ten.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 20:21:20 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/14 23:36:21 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		finish_algo(t_vec *va, t_vec *vb, t_vec *vp, int flag)
{
	if (ft_va_issorted(va))
	{
		v_append_raw(vp, ft_swap(va, vb, 'a'), 3);
		ft_print(va, vb, flag, "sa");
	}
	while (v_size(vb) > 0)
	{
		v_append_raw(vp, ft_push(va, vb, 'a'), 3);
		ft_print(va, vb, flag, "pa");
	}
}

void		algo_under_ten(t_vec *va, t_vec *vb, t_vec *vp, int flag)
{
	int *quart;
	int i;
	int size;
	int *fq;

	if (ft_sorted(va, vb))
		return ;
	fq = (int *)malloc(sizeof(int) * 2);
	fq[0] = flag;
	size = v_size(va);
	if (size > 8)
		size = 8;
	quart = ft_quartile(va);
	i = 1;
	while (i <= size)
	{
		fq[1] = quart[i++];
		sort_part_i(va, vb, vp, fq);
	}
	finish_algo(va, vb, vp, flag);
	free(quart);
	free(fq);
}
