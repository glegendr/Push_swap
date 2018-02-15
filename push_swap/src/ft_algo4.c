/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 22:26:59 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/16 00:53:48 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (ret);
}

int		sort_first_part(t_vec *va, t_vec *vb, t_vec *vp, int flag)
{
	int o;
	int quart;
	int y;

	y = 0;
	o = 0;
	quart = ft_quartile(va)[1];
	while (y < v_size(va))
	{
		if (vec_gsize(va, 1) <= quart)
		{
			while (nbef(vb, vec_gsize(va, 1)) != 0)
			{
				v_append_raw(vp, ft_rotate(va, vb, 'b'), 3);
				ft_print(va, vb, flag, "rb");
				++o;
			}
			while (v_size(vb) > 1 && nbef(vb, vec_gsize(va, 1)) >= v_size(vb) / 2 &&
					nbef(vb, vec_gsize(va, 1)) != 1)
			{
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
			if (nbef(vb, vec_gsize(va, 1)) != 0)
			{
				v_append_raw(vp, ft_rotate(va, vb, 'r'), 3);
				ft_print(va, vb, flag, "rr");
			}
			else
			{
				v_append_raw(vp, ft_rotate(va, vb, 'a'), 3);
				ft_print(va, vb, flag, "ra");
			}
			++y;
		}
		++o;
	}
	return (o);
}

int		ft_algo4(t_vec *va, t_vec *vb, t_vec *vp, int flag)
{
	int *quart;
	int o;
	int i;
	int y;

	quart = ft_quartile(va);
	i = 3;
	o = sort_first_part(va, vb, vp, flag);
	/*	while (i > 0)
		{
		y = 0;
		while (y < v_size(va))
		}*/
	return (o);
}

int main(int argc, const char *argv[])
{
	t_vec va;
	t_vec vb;
	int wh;

	va = v_new(sizeof(int));
	vb = v_new(sizeof(int));
	v_push_int(&va, 8);
	v_push_int(&va, 3);
	v_push_int(&va, 0);
	v_push_int(&vb, 4);
	v_push_int(&vb, 1);
	v_push_int(&vb, 7);
	ft_print(&va, &vb, 2, "rr");
	printf("%i\n", wh = nbef(&vb, 0));
	while (wh > 1)
	{
		ft_rotate(&va, &vb, 'b');
	ft_print(&va, &vb, 2, "rb");
		--wh;
	}
	ft_push(&va, &vb, 'b');
	ft_print(&va, &vb, 2, "pb");
	return 0;
}
