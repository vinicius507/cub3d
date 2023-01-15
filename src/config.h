/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:26:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/01/14 17:35:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <stdint.h>

typedef const char	*t_config_option;

typedef struct s_config
{
	t_config_option	no;
	t_config_option	so;
	t_config_option	we;
	t_config_option	ea;
	t_config_option	floor;
	t_config_option	ceiling;
}	t_config;

void	teardown_config(t_config *config);

int		load_config(const char *filename, t_config *config);

#endif
