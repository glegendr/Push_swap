/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 00:56:11 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/22 00:26:56 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "vector.h"

int		ft_isactions(char *s)
{
	if (!ft_strcmp(s, "rrr") || !ft_strcmp(s, "rra") || !ft_strcmp(s, "rrb") ||
			!ft_strcmp(s, "ra") || !ft_strcmp(s, "rb") || !ft_strcmp(s, "rr") ||
			!ft_strcmp(s, "sa") || !ft_strcmp(s, "sb") || !ft_strcmp(s, "pb") ||
			!ft_strcmp(s, "ss") || !ft_strcmp(s, "pa"))
		return (1);
	return (0);
}

void	ft_check_vp(t_vec *vp, t_vec *va, t_vec *vb)
{
	int i;

	i = 0;
	while (i < v_size(vp))
	{
		if (!ft_isactions((char *)v_get(vp, i)))
			ft_error(va, vb, vp);
		++i;
	}
}

void	ft_compare(t_vec *va, t_vec *vb, t_vec *vp, int i)
{
	if (ft_strcmp((char *)v_get(vp, i), "rrr") == 0)
		ft_reverse_rotate(va, vb, 'r');
	else if (ft_strcmp((char *)v_get(vp, i), "rra") == 0)
		ft_reverse_rotate(va, vb, 'a');
	else if (ft_strcmp((char *)v_get(vp, i), "rrb") == 0)
		ft_reverse_rotate(va, vb, 'b');
	else if (ft_strcmp((char *)v_get(vp, i), "rr") == 0)
		ft_rotate(va, vb, 'r');
	else if (ft_strcmp((char *)v_get(vp, i), "ra") == 0)
		ft_rotate(va, vb, 'a');
	else if (ft_strcmp((char *)v_get(vp, i), "rb") == 0)
		ft_rotate(va, vb, 'b');
	else if (ft_strcmp((char *)v_get(vp, i), "ss") == 0)
		ft_swap(va, vb, 's');
	else if (ft_strcmp((char *)v_get(vp, i), "sa") == 0)
		ft_swap(va, vb, 'a');
	else if (ft_strcmp((char *)v_get(vp, i), "sb") == 0)
		ft_swap(va, vb, 'b');
	else if (ft_strcmp((char *)v_get(vp, i), "pa") == 0)
		ft_push(va, vb, 'a');
	else if (ft_strcmp((char *)v_get(vp, i), "pb") == 0)
		ft_push(va, vb, 'b');
	else
		ft_error(va, vb, vp);
}

char	*ft_algo(t_vec *va, t_vec *vb, t_vec *vp, int flag)
{
	int i;

	i = 0;
	ft_check_vp(vp, va, vb);
	while (i < v_size(vp))
	{
		ft_compare(va, vb, vp, i);
		if (flag >= 1)
			ft_print(va, vb, flag, (char *)v_get(vp, i));
		++i;
	}
	if (ft_sorted(va, vb))
		return ("OK\n");
	return ("KO\n");
}
