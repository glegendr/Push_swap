/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:31:23 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/14 22:09:32 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		*quartile_into_int_sec(t_vec *va)
{
	int		*quart;

	quart = (int *)malloc(sizeof(int) * 14);
	quart[0] = 0;
	quart[1] = ((int *)v_get(va, v_size(va) * 0.08))[0];
	quart[2] = ((int *)v_get(va, v_size(va) * 0.16))[0];
	quart[3] = ((int *)v_get(va, v_size(va) * 0.24))[0];
	quart[4] = ((int *)v_get(va, v_size(va) * 0.32))[0];
	quart[5] = ((int *)v_get(va, v_size(va) * 0.40))[0];
	quart[6] = ((int *)v_get(va, v_size(va) * 0.48))[0];
	quart[7] = ((int *)v_get(va, v_size(va) * 0.56))[0];
	quart[8] = ((int *)v_get(va, v_size(va) * 0.64))[0];
	quart[9] = ((int *)v_get(va, v_size(va) * 0.72))[0];
	quart[10] = ((int *)v_get(va, v_size(va) * 0.80))[0];
	quart[11] = ((int *)v_get(va, v_size(va) * 0.88))[0];
	quart[12] = ((int *)v_get(va, v_size(va) * 0.96))[0];
	quart[13] = ((int *)v_get(va, v_size(va) - 4))[0];
	v_del(va);
	return (quart);
}

int		*quartile_into_int(t_vec *va)
{
	int		*quart;

	quart = (int *)malloc(sizeof(int) * 8);
	quart[0] = 0;
	quart[1] = ((int *)v_get(va, v_size(va) * 0.14))[0];
	quart[2] = ((int *)v_get(va, v_size(va) * 0.28))[0];
	quart[3] = ((int *)v_get(va, v_size(va) * 0.42))[0];
	quart[4] = ((int *)v_get(va, v_size(va) * 0.56))[0];
	quart[5] = ((int *)v_get(va, v_size(va) * 0.70))[0];
	quart[6] = ((int *)v_get(va, v_size(va) * 0.84))[0];
	quart[7] = ((int *)v_get(va, v_size(va) - 4))[0];
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
	if (v_size(&va) < 150)
		return (quartile_into_int(&va));
	return (quartile_into_int_sec(&va));
}
