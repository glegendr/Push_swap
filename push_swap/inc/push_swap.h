/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 00:33:20 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/09 00:38:13 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "vector.h"

void		ft_error(t_vec *va, t_vec *vb, t_vec *vp);
void		ft_divide(t_vec *va, t_vec *vb, t_vec *vp, int flag, int *o);
t_vec		*ft_algo(t_vec *va, t_vec *vb, t_vec *vp, int flag, int *o);
t_vec		*ft_algo2(t_vec *va, t_vec *vb, t_vec *vp, int flag, int *o);
void		ft_algo3(t_vec *va, t_vec *vb, t_vec *vp, int flag, int *o);
int			ft_sorted(t_vec *va, t_vec *vb);
int			ft_va_issorted2(t_vec *va);
int			ft_va_issorted(t_vec *va);
int			ft_vb_issorted(t_vec *vb);
void		ft_print(t_vec *va, t_vec *vb, int flag, char *s);
char		*ft_swap(t_vec *va, t_vec *vb, char c);
char		*ft_push(t_vec *va, t_vec *vb, char c);
char		*ft_rotate(t_vec *va, t_vec *vb, char c);
char		*ft_reverse_rotate(t_vec *va, t_vec *vb, char c);
#endif
