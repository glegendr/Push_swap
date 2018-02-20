/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:16:30 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/20 23:23:18 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "vector.h"

int		ft_vb_issorted(t_vec *vb)
{
	int i;

	i = 0;

	while (i < v_size(vb) - 1)
	{
		if (((int *)v_get(vb, i))[0] < ((int *)v_get(vb, i + 1))[0])
			return (((int *)v_get(vb, i))[0]);
		++i;
	}
	return (1);
}

int		ft_iterations_sort(t_vec *va)
{
	int i;
	int y;
	int max;

	max = -2147483648;
	y = 0;
	i = 0;
	while (i++ < v_size(va))
		if (max < vec_get(va, i - 1))
			max = vec_get(va, i - 1);
	while (i < v_size(va) - 1)
	{
		if (vec_get(va, i) < vec_get(va, i + 1) && vec_get(va, i + 1) != max)
			++y;
		++i;
	}
	return (y);
}

int		ft_va_issorted2(t_vec *va)
{
	int i;

	i = 0;
	while (i < v_size(va) - 1)
	{
		if (((int *)v_get(va, i))[0] < ((int *)v_get(va, i + 1))[0])
			return (0);
		++i;
	}
	return (1);
}

int		ft_va_issorted(t_vec *va)
{
	int i;

	i = 0;
	while (i < v_size(va) - 1)
	{
		if (((int *)v_get(va, i))[0] > ((int *)v_get(va, i + 1))[0])
			return (0);
		++i;
	}
	return (1);
}

int		ft_sorted(t_vec *va, t_vec *vb)
{
	int i;

	i = 0;
	if (v_size(vb) != 0)
		return (0);
	while (i < v_size(va) - 1)
	{
		if (((int *)v_get(va, i))[0] < ((int *)v_get(va, i + 1))[0])
			return (0);
		++i;
	}
	return (1);
}
