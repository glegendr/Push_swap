/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 00:55:00 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/15 00:06:39 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "vector.h"

char		*ft_swap(t_vec *va, t_vec *vb, char c)
{
	if (c == 'a' && v_size(va) > 1)
	{
		v_swap(va, v_size(va), v_size(va) - 1);
		return ("sa");
	}
	else if (c == 'b' && v_size(vb) > 1)
	{
		v_swap(vb, v_size(vb) - 1, v_size(vb) - 2);
		return ("sb");
	}
	else if (c == 's')
	{
		if (v_size(va) > 1)
			v_swap(va, v_size(va), v_size(va) - 1);
		if (v_size(vb) > 1)
			v_swap(vb, v_size(vb), v_size(vb) - 1);
		return ("ss");
	}
	else if (c == 'a')
		return ("sa");
	else
		return ("sb");
}

char		*ft_push(t_vec *va, t_vec *vb, char c)
{
	if (c == 'a' && v_size(vb) > 0)
	{
		v_push(va, v_get(vb, v_size(vb) - 1));
		v_del_last(vb);
		return ("pa");
	}
	else if (c == 'b' && v_size(va) > 0)
	{
		v_push(vb, v_get(va, v_size(va) - 1));
		v_del_last(va);
		return ("pb");
	}
	else if (c == 'a')
		return ("pa");
	else
		return ("pb");
}

char		*ft_rotate(t_vec *va, t_vec *vb, char c)
{
	if (c == 'a')
	{
		if (v_size(va) > 1)
			v_reverse_rotate(va);
		return ("ra");
	}
	else if (c == 'b')
	{
		if (v_size(vb) > 1)
			v_reverse_rotate(vb);
		return ("rb");
	}
	else
	{
		if (v_size(va) > 1)
			v_reverse_rotate(va);
		if (v_size(vb) > 1)
			v_reverse_rotate(vb);
		return ("rr");
	}
}

char		*ft_reverse_rotate(t_vec *va, t_vec *vb, char c)
{
	if (c == 'a')
	{
		if (v_size(va) > 1)
			v_rotate(va);
		return ("rra");
	}
	else if (c == 'b')
	{
		if (v_size(vb) > 1)
			v_rotate(vb);
		return ("rrb");
	}
	else
	{
		if (v_size(va) > 1)
			v_rotate(va);
		if (v_size(vb) > 1)
			v_rotate(vb);
		return ("rrr");
	}
}
