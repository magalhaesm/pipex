/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:54:11 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/05 12:55:47 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

t_flag	*flag_array(void)
{
	static t_flag	array[128];

	return (array);
}

void	init_parser(void)
{
	t_flag	*flags;

	flags = flag_array();
	flags['-'] = left;
	flags['0'] = padding;
	flags['+'] = showsign;
	flags[' '] = space;
	flags['#'] = hash;
}

void	clean_info(t_param *spec)
{
	spec->pad = ' ';
	spec->width = 0;
	spec->precision = -1;
	spec->prefix_len = 0;
	spec->prefix = "";
	spec->flags[LEFT] = FALSE;
	spec->flags[ZERO] = FALSE;
	spec->flags[PLUS] = FALSE;
	spec->flags[SPACE] = FALSE;
	spec->flags[HASH] = FALSE;
}

int	read_nbr(const char **format)
{
	int	nbr;

	nbr = 0;
	while (ft_isdigit(**format))
	{
		nbr = (nbr * 10) + (**format - '0');
		(*format)++;
	}
	return (nbr);
}

const char	*find_spec(const char *format)
{
	while (*format != '%' && *format)
		format++;
	return (format);
}
