/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:02:31 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/14 23:37:26 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		algo_under_two(t_vec *va, t_vec *vb, t_vec *vp, int flag)
{
	if (ft_sorted(va, vb))
		return ;
	if (v_size(va) == 1)
		return ;
	if (*(int *)v_get(va, 1) > *(int *)v_get(va, 0))
	{
		v_append_raw(vp, ft_swap(va, vb, 'a'), 3);
		ft_print(va, vb, flag, "sa");
	}
}

void		algo_under_five_end(t_vec *va, t_vec *vb, t_vec *vp, int flag)
{
	if (v_size(vb) > 1 && *(int *)v_get(vb, 0) < *(int *)v_get(vb, 1))
	{
		v_append_raw(vp, ft_swap(va, vb, 'b'), 3);
		ft_print(va, vb, flag, "sb");
	}
	while (v_size(vb) > 0)
	{
		if (nbef(va, *(int *)v_get(vb, v_size(vb) - 1), 0, 0) == v_size(va))
		{
			v_append_raw(vp, ft_push(va, vb, 'a'), 3);
			ft_print(va, vb, flag, "pa");
		}
		else
		{
			v_append_raw(vp, ft_rotate(va, vb, 'a'), 3);
			ft_print(va, vb, flag, "ra");
		}
	}
	while (!ft_sorted(va, vb))
	{
		v_append_raw(vp, ft_rotate(va, vb, 'a'), 3);
		ft_print(va, vb, flag, "ra");
	}
}

void		sort_va(t_vec *va, t_vec *vb, t_vec *vp, int flag)
{
	if (*(int *)v_get(va, 1) > *(int *)v_get(va, 0) &&
			*(int *)v_get(va, 1) > *(int *)v_get(va, 2))
	{
		v_append_raw(vp, ft_reverse_rotate(va, vb, 'a'), 4);
		ft_print(va, vb, flag, "rra");
	}
	else if (*(int *)v_get(va, 2) > *(int *)v_get(va, 1) &&
			*(int *)v_get(va, 0) > *(int *)v_get(va, 1))
	{
		v_append_raw(vp, ft_swap(va, vb, 'a'), 3);
		ft_print(va, vb, flag, "sa");
	}
	else if (*(int *)v_get(va, 2) > *(int *)v_get(va, 1) &&
			*(int *)v_get(va, 1) > *(int *)v_get(va, 0))
	{
		v_append_raw(vp, ft_swap(va, vb, 'a'), 3);
		ft_print(va, vb, flag, "sa");
		v_append_raw(vp, ft_reverse_rotate(va, vb, 'a'), 4);
		ft_print(va, vb, flag, "rra");
	}
}

void		algo_under_five(t_vec *va, t_vec *vb, t_vec *vp, int flag)
{
	if (v_size(va) < 3 || ft_sorted(va, vb))
		return (algo_under_two(va, vb, vp, flag));
	while (v_size(va) > 3)
	{
		v_append_raw(vp, ft_push(va, vb, 'b'), 3);
		ft_print(va, vb, flag, "pb");
	}
	sort_va(va, vb, vp, flag);
	if (*(int *)v_get(va, 1) > *(int *)v_get(va, 0))
	{
		v_append_raw(vp, ft_rotate(va, vb, 'a'), 3);
		ft_print(va, vb, flag, "ra");
		v_append_raw(vp, ft_swap(va, vb, 'a'), 3);
		ft_print(va, vb, flag, "sa");
		v_append_raw(vp, ft_reverse_rotate(va, vb, 'a'), 4);
		ft_print(va, vb, flag, "rra");
	}
	if (*(int *)v_get(va, 2) > *(int *)v_get(va, 1))
	{
		v_append_raw(vp, ft_swap(va, vb, 'a'), 3);
		ft_print(va, vb, flag, "sa");
	}
	if (v_size(vb) == 0)
		return ;
	algo_under_five_end(va, vb, vp, flag);
}
