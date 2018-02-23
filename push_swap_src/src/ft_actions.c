/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 00:55:00 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/22 21:29:17 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "vector.h"

char		*ft_swap(t_vec *va, t_vec *vb, char c)
{
	if (c == 'a' && v_size(va) > 1)
	{
		v_swap(va, v_size(va) - 1, v_size(va) - 2);
		return ("sa\n");
	}
	else if (c == 'b' && v_size(vb) > 1)
	{
		v_swap(vb, v_size(vb) - 1, v_size(vb) - 2);
		return ("sb\n");
	}
	else if (c == 's')
	{
		if (v_size(va) > 1)
			v_swap(va, v_size(va) - 1, v_size(va) - 2);
		if (v_size(vb) > 1)
			v_swap(vb, v_size(vb) - 1, v_size(vb) - 2);
		return ("ss\n");
	}
	else if (c == 'a')
		return ("sa\n");
	else
		return ("sb\n");
}

char		*ft_push(t_vec *va, t_vec *vb, char c)
{
	if (c == 'a' && v_size(vb) > 0)
	{
		v_push(va, v_get(vb, v_size(vb) - 1));
		v_del_last(vb);
		return ("pa\n");
	}
	else if (c == 'b' && v_size(va) > 0)
	{
		v_push(vb, v_get(va, v_size(va) - 1));
		v_del_last(va);
		return ("pb\n");
	}
	else if (c == 'a')
		return ("pa\n");
	else
		return ("pb\n");
}

char		*ft_rotate(t_vec *va, t_vec *vb, char c)
{
	if (c == 'a')
	{
		if (v_size(va) > 1)
			v_reverse_rotate(va);
		return ("ra\n");
	}
	else if (c == 'b')
	{
		if (v_size(vb) > 1)
			v_reverse_rotate(vb);
		return ("rb\n");
	}
	else
	{
		if (v_size(va) > 1)
			v_reverse_rotate(va);
		if (v_size(vb) > 1)
			v_reverse_rotate(vb);
		return ("rr\n");
	}
}

char		*ft_reverse_rotate(t_vec *va, t_vec *vb, char c)
{
	if (c == 'a')
	{
		if (v_size(va) > 1)
			v_rotate(va);
		return ("rra\n");
	}
	else if (c == 'b')
	{
		if (v_size(vb) > 1)
			v_rotate(vb);
		return ("rrb\n");
	}
	else
	{
		if (v_size(va) > 1)
			v_rotate(va);
		if (v_size(vb) > 1)
			v_rotate(vb);
		return ("rrr\n");
	}
}
