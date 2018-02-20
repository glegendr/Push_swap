/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 22:26:59 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/20 23:32:42 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		nbef(t_vec *v, int next)
{
	int i;
	int min;
	int ret;
	int check;

	ret = 0;
	i = 0;
	min = -2147483648;
	check = 0;
	while (i++ < v_size(v))
		if (vec_get(v, i - 1) > min && vec_get(v, i - 1) < next)
		{
			ret = v_size(v) - (i - 1);
			min = vec_get(v, i - 1);
			check = 1;
		}
	min = 2147483647;
	if (check == 0)
		while (i-- > 0)
			if (vec_get(v, i - 1) < min && vec_get(v, i - 1) > next)
			{
				ret = v_size(v) - (i - 2);
				min = vec_get(v, i - 1);
				check = 1;
			}
	if (ret > v_size(v))
		return (1);
	return (ret);
}

int		nbmin(t_vec *v)
{
	int min;
	int i;

	i = 0;
	min = 2147483647;
	while (i < v_size(v))
	{
		if (vec_get(v, i) < min)
			min = vec_get(v, i);
		++i;
	}
	return (min);
}

int		nbpos(t_vec *v, int nb)
{
	int pos;

	pos = 0;
	while (pos < v_size(v))
	{
		if (vec_get(v, pos) == nb)
			return (v_size(v) - pos);
		++pos;
	}
	return (v_size(v));
}

int		nextnb_inquart(t_vec *v, int quart)
{
	int i;

	i = 1;
	while (i < v_size(v))
	{
		if (vec_gsize(v, i) <= quart)
			return (vec_gsize(v, i));
		++i;
	}
	return (0);
}

int		sort_part_i(t_vec *va, t_vec *vb, t_vec *vp, int flag, int quart)
{
	int o;
	int y;

	y = 0;
	o = 0;
	while (y < v_size(va))
	{
		if (vec_gsize(va, 1) <= quart)
		{
			while (nbef(vb, vec_gsize(va, 1)) != 1 && v_size(vb) > 0 && nbef(vb, vec_gsize(va, 1)) < v_size(vb) / 2)
			{
				//				printf("Rb\n");
				v_append_raw(vp, ft_rotate(va, vb, 'b'), 3);
				ft_print(va, vb, flag, "rb");
				++o;
			}
			while (v_size(vb) > 1 && nbef(vb, vec_gsize(va, 1)) >= v_size(vb) / 2 &&
					nbef(vb, vec_gsize(va, 1)) != 1)
			{
				//				printf("RRR\n");
				v_append_raw(vp, ft_reverse_rotate(va, vb, 'b'), 4);
				ft_print(va, vb, flag, "rrb");
				++o;
			}
			v_append_raw(vp, ft_push(va, vb, 'b'), 3);
			ft_print(va, vb, flag, "pb");
			--y;
		}
		else
		{
			/*if (nbef(vb, vec_gsize(va, 1)) != 1 && nbef(vb, vec_gsize(va, 1)) > v_size(vb) / 2)
			  {
			//				printf("RR\n");
			v_append_raw(vp, ft_reverse_rotate(va, vb, 'b'), 4);
			ft_print(va, vb, flag, "rrb");
			}*/
			if ((nbef(vb, nextnb_inquart(va, quart)) != 1 && nbef(vb, nextnb_inquart(va, quart)) <= (v_size(vb) + nextnb_inquart(va, quart)) / 2))
			{
				//				printf("RR\n");
				v_append_raw(vp, ft_rotate(va, vb, 'r'), 3);
				ft_print(va, vb, flag, "rr");
				++y;
			}
			else
			{
				//				printf("RA\n");
				v_append_raw(vp, ft_rotate(va, vb, 'a'), 3);
				ft_print(va, vb, flag, "ra");
				++y;
			}
		}
		++o;
	}
	while (!ft_va_issorted(vb) && nbpos(vb, nbmin(vb)) < v_size(vb) / 2)
	{
		v_append_raw(vp, ft_rotate(va, vb, 'b'), 3);
		ft_print(va, vb, flag, "rb");
		++o;
	}
	while (!ft_va_issorted(vb))
	{
		v_append_raw(vp, ft_reverse_rotate(va, vb, 'b'), 4);
		ft_print(va, vb, flag, "rrb");
		++o;
	}
	return (o);
}

int		ft_algo(t_vec *va, t_vec *vb, t_vec *vp, int flag)
{
	int *quart;
	int o;
	int i;

	o = 0;
	if (ft_sorted(va, vb))
		return (0);
	quart = ft_quartile(va);
	i = 1;
	while (i <= 10)
	{
		o += sort_part_i(va, vb, vp, flag, quart[i]);
		++i;
	}
	while (v_size(vb) > 0)
	{
		v_append_raw(vp, ft_push(va, vb, 'a'), 3);
		ft_print(va, vb, flag, "pa");
		++o;
	}
	return (o);
}
