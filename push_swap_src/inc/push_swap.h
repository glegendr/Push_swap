/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 00:33:20 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/13 20:29:09 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "vector.h"

void		sort_part_i(t_vec *va, t_vec *vb, t_vec *vp, int *fq);
char		**carve_argv(int *argc, char **argv);
void		ft_error(void);
void		ft_algo(t_vec *va, t_vec *vb, t_vec *vp, int flag);
void		algo_under_ten(t_vec *va, t_vec *vb, t_vec *vp, int flag);
void		algo_under_five(t_vec *va, t_vec *vb, t_vec *vp, int flag);
int			ft_sorted(t_vec *va, t_vec *vb);
int			*ft_quartile(t_vec *vc);
int			ft_va_issorted(t_vec *va);
void		check_int(int argc, char **argv);
void		ft_print(t_vec *va, t_vec *vb, int flag, char *s);
char		*ft_swap(t_vec *va, t_vec *vb, char c);
char		*ft_push(t_vec *va, t_vec *vb, char c);
char		*ft_rotate(t_vec *va, t_vec *vb, char c);
char		*ft_reverse_rotate(t_vec *va, t_vec *vb, char c);
int			nbef(t_vec *v, int next, int ret, int i);
int			nbmin(t_vec *v);
int			nbpos(t_vec *v, int nb);
int			nextnb_inquart(t_vec *v, int quart);
#endif
