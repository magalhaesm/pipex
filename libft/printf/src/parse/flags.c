/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:36:19 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/05 12:26:42 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

void	left(t_param *spec)
{
	spec->flags[LEFT] = TRUE;
	spec->flags[ZERO] = FALSE;
}

void	padding(t_param *spec)
{
	if (spec->flags[LEFT])
		return ;
	spec->flags[ZERO] = TRUE;
}

void	showsign(t_param *spec)
{
	spec->flags[PLUS] = TRUE;
	spec->flags[SPACE] = FALSE;
}

void	space(t_param *spec)
{
	if (spec->flags[PLUS])
		return ;
	spec->flags[SPACE] = TRUE;
}

void	hash(t_param *spec)
{
	spec->flags[HASH] = TRUE;
}
