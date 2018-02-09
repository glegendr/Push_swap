/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 02:12:24 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/09 00:00:22 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "vector.h"
#include "libft.h"

t_vec		*ft_algo2(t_vec *va, t_vec *vb, t_vec *vp, int flag, int *o)
{
	int i;
	char *s;
	int min;
	int min2;
	int pos;
	int pos2;

	while (v_size(va) > 2 && !ft_va_issorted2(va))
	{
		i = 0;
		min = 2147483647;
		min2 = 2147483647;
		while (i < v_size(va))
		{
			if (min > ft_atoi(v_get(va, i)))
			{
				min2 = min;
				pos2 = pos;
				min = ft_atoi(v_get(va, i));
				pos = i;
			}
			if (min2 > ft_atoi(v_get(va, i)) && min != ft_atoi(v_get(va, i)))
			{
				min2 = ft_atoi(v_get(va, i));
				pos2 = i;
			}
			++i;
		}
		printf("%i\t%i\n", min, min2);
		if ((pos < v_size(va) / 2 && pos2 < pos) ||(pos > v_size(va) / 2 && pos2 > pos))
			{
				min = min2;
				pos = pos2;
			}
		if (pos >= v_size(va) / 2)
			while (min != ft_atoi(v_get(va, v_size(va) - 1)))
			{
				v_append_raw(vp, s = ft_rotate(va, vb, 'a'), 2);
				ft_print(va, vb, flag, s);
				v_push(vp, "\n");
				*o += 1;
			}
		else
			while (min != ft_atoi(v_get(va, v_size(va) - 1)))
			{
				v_append_raw(vp, s = ft_reverse_rotate(va, vb, 'a'), 3);
				ft_print(va, vb, flag, s);
				v_push(vp, "\n");
				*o += 1;
			}
		if (!ft_va_issorted2(va))
		{
			v_append_raw(vp, s = ft_push(va, vb, 'b'), 2);
			ft_print(va, vb, 2, s);
			v_push(vp, "\n");
			*o += 1;
			if (ft_atoi(v_get(vb, v_size(vb) - 1)) < ft_atoi(v_get(vb, v_size(vb) - 2)))
			{
			v_append_raw(vp, s = ft_swap(va, vb, 'b'), 2);
			ft_print(va, vb, flag, s);
			v_push(vp, "\n");
			*o += 1;
			}
		}
	}
	if (!ft_va_issorted2(va))
	{
			v_append_raw(vp, s = ft_swap(va, vb, 'a'), 2);
			ft_print(va, vb, flag, s);
			v_push(vp, "\n");
			*o += 1;
	}
	while (v_size(vb) > 0)
	{
			v_append_raw(vp, s = ft_push(va, vb, 'a'), 2);
			ft_print(va, vb, flag, s);
			v_push(vp, "\n");
			*o += 1;
				if (ft_atoi(v_get(va, v_size(va) - 1)) > ft_atoi(v_get(va, v_size(va) - 2)))
				{
			v_append_raw(vp, s = ft_swap(va, vb, 'a'), 2);
			ft_print(va, vb, flag, s);
			v_push(vp, "\n");
			*o += 1;
				}
	}
	return (vp);
}
t_vec		*ft_algo(t_vec *va, t_vec *vb, t_vec *vp, int flag, int *o)
{
	char *s;
	int max;
	int i;

	i = 0;
	max = -2147483648;
	while (i < v_size(va))
	{
		if (max <= ft_atoi(v_get(va, i)))
			max = ft_atoi(v_get(va, i));
		++i;
	}
	while (!ft_va_issorted2(va))
	{
		if (ft_atoi(v_get(va, v_size(va) - 1)) > ft_atoi(v_get(va, v_size(va) - 2)) && ft_atoi(v_get(va, v_size(va) - 1)) != max)
		{
			v_append_raw(vp, s = ft_swap(va, vb, 'a'), 2);
			ft_print(va, va, flag, s);
			v_push(vp, "\n");
				*o += 1;
		}
		else
		{
			v_append_raw(vp, s = ft_rotate(va, vb, 'a'), 3);
			ft_print(va, va, flag, s);
			v_push(vp, "\n");
				*o += 1;
		}
	}
	while (v_size(vb) > 0)
	{
			v_append_raw(vp, s = ft_push(va, vb, 'a'), 2);
			ft_print(va, vb, flag, s);
			v_push(vp, "\n");
				*o += 1;
	}
	return (vp);
}
