/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 05:38:33 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/13 20:47:49 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_to_b(t_vec *va, t_vec *vb, t_vec *vp, int *fq)
{
	while (nbef(vb, *(int *)v_get(va, v_size(va) - 1), 0, 0) != 1 &&
			v_size(vb) > 0 &&
			nbef(vb, *(int *)v_get(va, v_size(va) - 1), 0, 0) < v_size(vb) / 2)
	{
		v_append_raw(vp, ft_rotate(va, vb, 'b'), 3);
		ft_print(va, vb, fq[0], "rb");
	}
	while (v_size(vb) > 1 &&
			nbef(vb, *(int *)v_get(va, v_size(va) - 1), 0, 0) >= v_size(vb) / 2
			&& nbef(vb, *(int *)v_get(va, v_size(va) - 1), 0, 0) != 1)
	{
		v_append_raw(vp, ft_reverse_rotate(va, vb, 'b'), 4);
		ft_print(va, vb, fq[0], "rrb");
	}
	v_append_raw(vp, ft_push(va, vb, 'b'), 3);
	ft_print(va, vb, fq[0], "pb");
}

void		rotate_a(t_vec *va, t_vec *vb, t_vec *vp, int *fq)
{
	if ((nbef(vb, nextnb_inquart(va, fq[1]), 0, 0) != 1 &&
				nbef(vb, nextnb_inquart(va, fq[1]), 0, 0)
				<= (v_size(vb) + nextnb_inquart(va, fq[1])) / 2))
	{
		v_append_raw(vp, ft_rotate(va, vb, 'r'), 3);
		ft_print(va, vb, fq[0], "rr");
	}
	else
	{
		v_append_raw(vp, ft_rotate(va, vb, 'a'), 3);
		ft_print(va, vb, fq[0], "ra");
	}
}

void		sort_part_i(t_vec *va, t_vec *vb, t_vec *vp, int *fq)
{
	int y;

	y = 0;
	while (y < v_size(va))
		if (*(int *)v_get(va, v_size(va) - 1) <= fq[1])
		{
			push_to_b(va, vb, vp, fq);
			--y;
		}
		else
		{
			rotate_a(va, vb, vp, fq);
			++y;
		}
	while (!ft_va_issorted(vb) && nbpos(vb, nbmin(vb)) < v_size(vb) / 2)
	{
		v_append_raw(vp, ft_rotate(va, vb, 'b'), 3);
		ft_print(va, vb, fq[0], "rb");
	}
	while (!ft_va_issorted(vb))
	{
		v_append_raw(vp, ft_reverse_rotate(va, vb, 'b'), 4);
		ft_print(va, vb, fq[0], "rrb");
	}
}
