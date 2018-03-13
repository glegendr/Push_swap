/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 00:04:44 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/15 00:15:28 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"

void		v_rotate(t_vec *vec)
{
	void *tmp;

	tmp = malloc(vec->private_elem_size);
	ft_memcpy(tmp, v_get(vec, 0), vec->private_elem_size);
	ft_memcpy(v_get(vec, 0), v_get(vec, 1), (vec->private_elem_nb - 1)
			* vec->private_elem_size);
	ft_memcpy(v_get(vec, v_size(vec) - 1), tmp, vec->private_elem_size);
	free(tmp);
}
