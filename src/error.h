/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:51:37 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/12/27 16:34:32 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef const char	*t_err;

t_err	error(const char *msg);

t_err	error_from(const char *msg, t_err err_from);

void	print_error(t_err err);

#endif
