/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caster.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:47:52 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/23 23:03:06 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTING_HPP
# define CASTING_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <cmath>

# define CHAR_MIN_DISPLAYABLE 32
# define CHAR_MAX_DISPLAYABLE 127

enum e_cast_type
{
	ERROR_TYPE,
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE
};

enum e_cast_errors
{
	CHAR_NONDISP = 0b1,
	CHAR_IMPOS = 0b10,
	INT_IMPOS = 0b100
};


typedef struct s_convertion_table
{
	std::string		c;
	int				i;
	float			f;
	double			d;
	int				err_flags;
}	t_conv_tab;

#endif