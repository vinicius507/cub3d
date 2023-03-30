/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:28:49 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/03/30 18:45:02 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "libft.h"
#include "libft/ft_ctype.h"
#include <unistd.h>

static int	set_spec_value(unsigned char *spec, char *key, char *value)
{
	int		spec_value;

	if ((ft_isdigit(*value) == 0))
	{
		ft_dprintf(STDERR_FILENO, ERR_CFG_WRONG_OPTION_VALUE, key);
		return (1);
	}
	spec_value = ft_atoi(value);
	if (spec_value < 0 || spec_value > 255)
	{
		ft_dprintf(STDERR_FILENO, ERR_CFG_WRONG_OPTION_VALUE, key);
		return (1);
	}
	*spec = (unsigned char)spec_value;
	return (0);
}

static int	parse_rgb_string(t_color *option, char *key, char *value)
{
	size_t	i;
	int		spec_count;

	i = 0;
	spec_count = 3;
	while (spec_count > 0)
	{
		if ((set_spec_value(&option->rgb[spec_count - 1], key, &value[i]) != 0))
			return (1);
		while ((ft_isdigit(value[i]) != 0))
			i++;
		spec_count--;
		if ((spec_count > 0 && value[i] != ',')
			|| (spec_count == 0 && value[i] != '\0'))
		{
			ft_dprintf(STDERR_FILENO, ERR_CFG_WRONG_OPTION_VALUE, key);
			return (1);
		}
		i++;
	}
	return (0);
}

int	load_color_option(t_color *option, char *key, char *value)
{
	static char	is_ceil_set;
	static char	is_floor_set;

	if ((*key == 'C' && is_ceil_set == 1) || (*key == 'F' && is_floor_set == 1))
	{
		ft_dprintf(STDERR_FILENO, ERR_CFG_DUPLICATE_KEY, key);
		return (1);
	}
	if ((parse_rgb_string(option, key, value) != 0))
		return (1);
	if (*key == 'C')
		is_ceil_set = 1;
	if (*key == 'F')
		is_floor_set = 1;
	return (0);
}
