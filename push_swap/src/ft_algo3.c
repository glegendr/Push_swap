/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 00:00:31 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/09 03:37:48 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "vector.h"

int		*ft_quartile(t_vec *vc)
{
	int i;
	int y;
	int *quart;
	t_vec va;

	va = v_copy(vc);
	quart = (int *)malloc(sizeof(int) * 3);
	i = 0;
	while (i < v_size(&va))
	{
		y = 0;
		while (y < v_size(&va) - 1)
		{
			if (ft_atoi(v_get(&va, y)) > ft_atoi(v_get(&va, y + 1)))
				v_swap(&va, y, y + 1);
			++y;
		}
		++i;
	}
	i = 0;
	while (i < v_size(&va))
		printf("%s\n", v_get(&va, i++));
	quart[0] = ft_atoi(v_get(&va, v_size(&va) * 0.25));
	quart[1] = ft_atoi(v_get(&va, v_size(&va) * 0.5));
	quart[2] = ft_atoi(v_get(&va, v_size(&va) * 0.75));
	return (quart);
}

void	ft_algo3(t_vec *va, t_vec *vb, t_vec *vp, int flag, int *o)
{
	int *quartile;
	int i;
	int y;
	quartile = ft_quartile(va);
	i = 0;
	while (i < 1)
	{
		printf("%i\t%i\t%i\n", quartile[0], quartile[1], quartile[2]);
		y = quartile[0];
		while (y > 0)
		{
			//printf("%i\t%i\n", ft_atoi(v_get(va, v_size(va) - 1)), quartile[i]);
			if (ft_atoi(v_get(va, v_size(va) - 1)) <= quartile[i])
			{
				ft_push(va, vb, 'b');
			//	ft_print(va, vb, flag, "pb");
			//	v_push(vp, "\n");
				--y;
			}
			else
			{
				v_append_raw(vp, ft_rotate(va, vb, 'a'), 2);
				//ft_print(va, vb, flag, "ra");
		//		v_push(vp, "\n");
			}
			*o += 1;
		}
		//ft_sort_vb(va, vb, flag, o);
		++i;
	}
}
