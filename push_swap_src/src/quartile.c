/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:31:23 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/23 05:14:49 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		*quartile_into_int(t_vec *va)
{
	int		*quart;

	quart = (int *)malloc(sizeof(int) * 11);
	quart[0] = 0;
	quart[1] = ((int *)v_get(va, v_size(va) * 0.1))[0];
	quart[2] = ((int *)v_get(va, v_size(va) * 0.2))[0];
	quart[3] = ((int *)v_get(va, v_size(va) * 0.3))[0];
	quart[4] = ((int *)v_get(va, v_size(va) * 0.4))[0];
	quart[5] = ((int *)v_get(va, v_size(va) * 0.5))[0];
	quart[6] = ((int *)v_get(va, v_size(va) * 0.6))[0];
	quart[7] = ((int *)v_get(va, v_size(va) * 0.7))[0];
	quart[8] = ((int *)v_get(va, v_size(va) * 0.8))[0];
	quart[9] = ((int *)v_get(va, v_size(va) * 0.9))[0];
	quart[10] = ((int *)v_get(va, v_size(va) - 2))[0];
	v_del(va);
	return (quart);
}

int		*ft_quartile(t_vec *vc)
{
	int		i;
	int		y;
	t_vec	va;

	va = v_copy(vc);
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
	return (quartile_into_int(&va));
}
