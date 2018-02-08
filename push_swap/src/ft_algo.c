/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 02:12:24 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/08 04:33:04 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "vector.h"
#include "libft.h"

t_vec		*ft_algo2(t_vec *va, t_vec *vb, t_vec *vp, int flag, int *o)
{
	int i;
	int min;

	while (v_size(va) > 0)
	{
		i = 0;
		min = 2147483647;
		while (i < v_size(va))
		{
			if (min)
				//FAIRE LE TRI DU PLUS PETIT -> vb puis tout vb vers va :D
			++i;
		}
	}
}
t_vec		*ft_algo(t_vec *va, t_vec *vb, t_vec *vp, int flag, int *o)
{
	char *s;
	int littleb;
	int littlea;
	int i;

	i = 0;
	littlea = 2147483647;
	littleb = 2147483647;
	while (v_size(va) > v_size(vb))
	{
		v_append_raw(vp, s = ft_push(va, vb, 'b'), 2);
		ft_print(va, vb, flag, s);
		v_push(vp, "\n");
		if (littleb >= ft_atoi(v_get(vb, v_size(vb) - 1)))
			littleb = ft_atoi(v_get(vb, v_size(vb) - 1));
	*o += 1;
	}
	while (i < v_size(va))
	{
		if (littlea >= ft_atoi(v_get(va, i)))
			littlea = ft_atoi(v_get(va, i));
		++i;
	}
	while (!ft_va_issorted(va) || !ft_vb_issorted(vb))
	{
		if (ft_atoi(v_get(va, v_size(va) - 1)) < ft_atoi(v_get(va, v_size(va) - 2)) && ft_atoi(v_get(vb, v_size(vb) - 1)) < ft_atoi(v_get(vb, v_size(vb) - 2)))
		{
			v_append_raw(vp, s = ft_swap(va, vb, 's'), 2);
			ft_print(va, vb, flag, s);
			v_push(vp, "\n");
			v_append_raw(vp, s = ft_reverse_rotate(va, vb, 'r'), 3);
			ft_print(va, vb, flag, s);
			v_push(vp, "\n");
	*o += 2;
		}
		else if (ft_atoi(v_get(va, v_size(va) - 1)) < ft_atoi(v_get(va, v_size(va) - 2)) && ft_atoi(v_get(va, v_size(va) - 1)) > littlea)
		{
		//	printf("%i\t%i\n", littleb, littlea);
			v_append_raw(vp, s = ft_swap(va, vb, 'a'), 2);
			ft_print(va, vb, flag, s);
			v_push(vp, "\n");
			v_append_raw(vp, s = ft_reverse_rotate(va, vb, 'a'), 3);
			ft_print(va, vb, flag, s);
			v_push(vp, "\n");
	*o += 2;
		}
		else if (ft_atoi(v_get(vb, v_size(vb) - 1)) < ft_atoi(v_get(vb, v_size(vb) - 2)) && ft_atoi(v_get(vb, v_size(vb) - 1)) > littleb)
		{
		//	printf("%i\t%i\n", littleb, littlea);
			v_append_raw(vp, s = ft_swap(va, vb, 'b'), 2);
			ft_print(va, vb, flag, s);
			v_push(vp, "\n");
			v_append_raw(vp, s = ft_reverse_rotate(va, vb, 'b'), 2);
			ft_print(va, vb, flag, s);
			v_push(vp, "\n");
	*o += 2;
		}
		if (!ft_va_issorted(va) && !ft_vb_issorted(vb))
		{
		//	printf("%i\t%i\n", littleb, littlea);
			v_append_raw(vp, s = ft_reverse_rotate(va, vb, 'r'), 3);
			ft_print(va, vb, flag, s);
			v_push(vp, "\n");
	*o += 1;
		}
		else if (!ft_va_issorted(va))
		{
		//	printf("%i\t%i\n", littleb, littlea);
			v_append_raw(vp, s = ft_reverse_rotate(va, vb, 'a'), 3);
			ft_print(va, vb, flag, s);
			v_push(vp, "\n");
	*o += 1;
		}
		else if (!ft_vb_issorted(vb))
		{
			//printf("%i\t%i\n", littleb, littlea);
			v_append_raw(vp, s = ft_reverse_rotate(va, vb, 'b'), 3);
			ft_print(va, vb, flag, s);
			v_push(vp, "\n");
	*o += 1;
		}
	}
	return (vp);
}
