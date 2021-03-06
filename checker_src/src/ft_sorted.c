/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:16:30 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/13 20:31:57 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "vector.h"

int		ft_sorted(t_vec *va, t_vec *vb)
{
	int i;

	i = 0;
	if (v_size(vb) != 0)
		return (0);
	while (i < v_size(va) - 1)
	{
		if (*(int *)v_get(va, i) < *(int *)v_get(va, i + 1))
			return (0);
		++i;
	}
	return (1);
}
