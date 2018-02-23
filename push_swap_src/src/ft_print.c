/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 00:08:03 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/23 05:01:54 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "vector.h"

int		ft_search(t_vec *vec, char *v, char *s, int index)
{
	if (!ft_strcmp(s, "rrr") || !ft_strcmp(s, "rr") || (!ft_strcmp(s, "ss") &&
				(index == v_size(vec) || index == v_size(vec) - 1)))
		return (1);
	if ((!ft_strcmp(s, "ra") || !ft_strcmp(s, "rra")) && !ft_strcmp(v, "va"))
		return (1);
	if ((!ft_strcmp(s, "rb") || !ft_strcmp(s, "rrb")) && !ft_strcmp(v, "vb"))
		return (1);
	if (((!ft_strcmp(s, "pb") && !ft_strcmp(v, "vb")) || (!ft_strcmp(s, "pa") &&
					!ft_strcmp(v, "va"))) && index == v_size(vec))
		return (1);
	if (!ft_strcmp(s, "sa") && !ft_strcmp(v, "va") &&
			(index == v_size(vec) || index == v_size(vec) - 1))
		return (1);
	if (!ft_strcmp(s, "sb") && !ft_strcmp(v, "vb") &&
			(index == v_size(vec) || index == v_size(vec) - 1))
		return (1);
	return (0);
}

void	ft_color(int nb, int flag, int act, int i)
{
	char *s;

	if (nb != 0)
		s = ft_itoa(nb);
	if (flag == 2 && act == 1)
		write(1, "\033[33m", 5);
	if (nb != 0)
		write(1, s, ft_strlen(s));
	else
		write(1, "0", 1);
	if (i == 1 && nb != 0)
		write(1, "            ", 12 - ft_strlen(s));
	else if (i == 1)
		write(1, "           ", 11);
	if (flag == 2 && act == 1)
		write(1, "\033[00m", 5);
	if (nb != 0)
		free(s);
}

void	ft_print(t_vec *va, t_vec *vb, int flag, char *s)
{
	int r;

	if (flag == 0)
		return ;
	r = v_size(va);
	if (r < v_size(vb))
		r = v_size(vb);
	while (r > 0)
	{
		if (v_size(va) >= r)
			ft_color(VEC_GET(va, r - 1), flag, ft_search(va, "va", s, r), 1);
		else
			write(1, "            ", 12);
		if (v_size(vb) >= r)
			ft_color(VEC_GET(vb, r - 1), flag, ft_search(vb, "vb", s, r), 0);
		write(1, "\n", 1);
		--r;
	}
	write(1, "------------------------\n a            b\n\n", 41);
}
