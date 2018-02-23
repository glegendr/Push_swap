/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 00:56:11 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/23 04:45:42 by glegendr         ###   ########.fr       */
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
	int y;
	char *s;

	i = 0;
	while (i < v_size(vp))
	{
		y = 0;
		while ((char)vec_get(vp, i + y++) != '\n');
		s = (char *)malloc(sizeof(char) * y);
		y = 0;
		while ((char)vec_get(vp, i) != '\n')
		{
			s[y++] = vec_get(vp, i);
			++i;
		}
		s[y] = '\0';
		if (!ft_isactions(s))
			ft_error(va, vb, vp);
		++i;
		free(s);
	}
}

char	*ft_compare(t_vec *va, t_vec *vb, t_vec *vp, int *i)
{
	char *s;
	int y;

	y = 0;
	while ((char)vec_get(vp, *i + y++) != '\n');
	s = (char *)malloc(sizeof(char) * y);
	y = 0;
	while ((char)vec_get(vp, *i) != '\n')
	{
		s[y++] = vec_get(vp, *i);
		*i += 1;
	}
	s[y] = '\0';
	if (ft_strcmp(s, "rrr") == 0)
		ft_reverse_rotate(va, vb, 'r');
	else if (ft_strcmp(s, "rra") == 0)
		ft_reverse_rotate(va, vb, 'a');
	else if (ft_strcmp(s, "rrb") == 0)
		ft_reverse_rotate(va, vb, 'b');
	else if (ft_strcmp(s, "rr") == 0)
		ft_rotate(va, vb, 'r');
	else if (ft_strcmp(s, "ra") == 0)
		ft_rotate(va, vb, 'a');
	else if (ft_strcmp(s, "rb") == 0)
		ft_rotate(va, vb, 'b');
	else if (ft_strcmp(s, "ss") == 0)
		ft_swap(va, vb, 's');
	else if (ft_strcmp(s, "sa") == 0)
		ft_swap(va, vb, 'a');
	else if (ft_strcmp(s, "sb") == 0)
		ft_swap(va, vb, 'b');
	else if (ft_strcmp(s, "pa") == 0)
		ft_push(va, vb, 'a');
	else if (ft_strcmp(s, "pb") == 0)
		ft_push(va, vb, 'b');
	return (s);
}

char	*ft_algo(t_vec *va, t_vec *vb, t_vec *vp, int flag)
{
	int i;
	char *s;

	i = 0;
	ft_check_vp(vp, va, vb);
	while (i < v_size(vp))
	{
		s = ft_compare(va, vb, vp, &i);
		if (flag >= 1)
			ft_print(va, vb, flag, s);
		free(s);
		++i;
	}
	if (ft_sorted(va, vb))
		return ("OK\n");
	return ("KO\n");
}
