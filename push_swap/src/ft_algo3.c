/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 00:00:31 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/15 21:14:35 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "vector.h"

void	ft_sort_vb(int quart, t_vec *vb, int flag, int *o, t_vec *vp)
{
	int i;
	int min;

	min = -2147483648;
	i = 0;
	while (v_size(vb) > i++)
		if (((int *)v_get(vb, i - 1))[0] > min)
			min = ((int *)v_get(vb, i - 1))[0];
	i = 0;
	while (!ft_va_issorted2(vb))
	{
		printf("%i\n", quart);
		while (i < quart - 1 && !ft_va_issorted2(vb))
		{
			if (((int *)v_get(vb, v_size(vb) - 1))[0] > ((int *)v_get(vb, v_size(vb) - 2))[0] && ((int *)v_get(vb, v_size(vb) - 1))[0] != min)
			{
				v_append_raw(vp, ft_swap(vb, vb, 'b'), 2);
				ft_print(vb, vb, flag, "sb");
						v_push(vp, "\n");
				*o += 1;
			}
			if (ft_va_issorted2(vb))
				break ;
				v_append_raw(vp, ft_rotate(vb, vb, 'b'), 2);
			ft_print(vb, vb, flag, "rb");
						v_push(vp, "\n");
			++i;
			*o += 1;
		}
		while (i > 0 && !ft_va_issorted2(vb))
		{
			if (((int *)v_get(vb, v_size(vb) - 1))[0] > ((int *)v_get(vb, v_size(vb) - 2))[0] && ((int *)v_get(vb, v_size(vb) - 1))[0] != min)
			{
				v_append_raw(vp, ft_swap(vb, vb, 'b'), 2);
				ft_print(vb, vb, flag, "sb");
						v_push(vp, "\n");
				*o += 1;
			}
			if (ft_va_issorted2(vb))
				break ;
			v_append_raw(vp, ft_reverse_rotate(vb, vb, 'b'), 3);
			ft_print(vb, vb, flag, "rrb");
						v_push(vp, "\n");
			*o += 1;
			--i;
		}
	}
}

void	ft_sort_va(int quart, t_vec *vb, int flag, int *o, t_vec *vp)
{
	int i;
	int min;

	min = 2147483647;
	i = 0;
	while (v_size(vb) > i++)
		if (((int *)v_get(vb, i - 1))[0] < min)
			min = ((int *)v_get(vb, i - 1))[0];
	while (!ft_va_issorted(vb))
	{
		i = 0;
		while (i < quart && !ft_va_issorted(vb))
		{
			if (((int *)v_get(vb, v_size(vb) - 1))[0] < ((int *)v_get(vb, v_size(vb) - 2))[0] && ((int *)v_get(vb, v_size(vb) - 1))[0] != min)
			{
					ft_swap(vb, vb, 'b');
					v_append_raw(vp, "sa\n", 3);
				ft_print(vb, vb, flag, "sa");
				*o += 1;
			}
			if (ft_va_issorted(vb))
				break ;
				v_append_raw(vp, ft_rotate(vb, vb, 'a'), 2);
			ft_print(vb, vb, flag, "ra");
						v_push(vp, "\n");
			++i;
			*o += 1;
		}
		while (i > 0 && !ft_va_issorted(vb))
		{
			if (((int *)v_get(vb, v_size(vb) - 1))[0] < ((int *)v_get(vb, v_size(vb) - 2))[0] && ((int *)v_get(vb, v_size(vb) - 1))[0] != min)
			{
				v_append_raw(vp, ft_swap(vb, vb, 'a'), 2);
				ft_print(vb, vb, flag, "sb");
						v_push(vp, "\n");
				*o += 1;
			}
			if (ft_va_issorted(vb))
				break ;
			v_append_raw(vp, ft_reverse_rotate(vb, vb, 'a'), 3);
			ft_print(vb, vb, flag, "rrb");
						v_push(vp, "\n");
			*o += 1;
			--i;
		}
	}
}

int		*ft_quartile(t_vec *vc)
{
	int i;
	int y;
	int *quart;
	t_vec va;

	va = v_copy(vc);
	quart = (int *)malloc(sizeof(int) * 4);
	i = 0;
	while (i < v_size(&va))
	{
		y = 0;
		while (y < v_size(&va) - 1)
		{
			if (((int *)v_get(&va, y))[0] > ((int *)v_get(&va, y + 1))[0])
				v_swap(&va, y, y + 1);
			++y;
		}
		++i;
	}
	quart[0] = 0;
	quart[1] = ((int *)v_get(&va, v_size(&va) * 0.25))[0];
	quart[2] = ((int *)v_get(&va, v_size(&va) * 0.5))[0];
	quart[3] = ((int *)v_get(&va, v_size(&va) * 0.75))[0];
	return (quart);
}

void	ft_algo3(t_vec *va, t_vec *vb, t_vec *vp, int flag, int *o)
{
	int *quartile;
	int i;
	int y;
	quartile = ft_quartile(va);
	printf("%i\t%i\t%i\n", quartile[1], quartile[2], quartile[3]);
	i = 3;
	while (i > 0)
	{
		y = 0;
		while (y < v_size(va))
		{
			if (((int *)v_get(va, v_size(va) - 1))[0] > quartile[i])
			{
				v_append_raw(vp, ft_push(va, vb, 'b'), 2);
				//	ft_print(va, vb, flag, "pb");
					v_push(vp, "\n");
				if (((int *)v_get(vb, v_size(vb) - 1))[0] > ((int *)v_get(vb, v_size(vb) - 2))[0])
				{
				v_append_raw(vp, ft_swap(va, vb, 'b'), 2);
					ft_print(va, vb, flag, "sb");
					v_push(vp, "\n");
					*o += 1;
				}
/*				if (((int *)v_get(va, v_size(va) - 1))[0] < ((int *)v_get(va, v_size(va) - 2))[0] && ((int *)v_get(va, v_size(va) - 2))[0] < quartile[i])
				{
					ft_swap(va, vb, 'a');
					ft_print(va, vb, flag, "sa");
					*o += 1;
				}*/
				--y;
			}
			else
			{
				v_append_raw(vp, ft_rotate(va, vb, 'a'), 2);
				//ft_print(va, vb, flag, "ra");
						v_push(vp, "\n");
				++y;
			}
			*o += 1;
		}
	//	ft_print(va, vb, 2, "rrr");
		printf("%i\t%i\t%i\n", v_size(va), i, quartile[1]);
		ft_sort_vb(quartile[1], vb, flag, o, vp);
		--i;
	}
	ft_sort_va(v_size(va), va, flag, o, vp);
	while (v_size(vb) > 0)
	{
		v_append_raw(vp, ft_push(va, vb, 'a'), 2);
		v_push(vp, "\n");
		*o += 1;
	}
}
