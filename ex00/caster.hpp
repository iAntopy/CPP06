/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caster_alt.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:47:52 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/30 21:31:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTING_HPP
# define CASTING_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <cmath>
# include <limits>

# define DIGITS "0123456789"
# define DISP_CHAR_MIN 32
# define DISP_CHAR_MAX 127

enum e_num_type
{
	CHAR_TYPE,
	INT_TYPE,
	FLT_TYPE,
	DBL_TYPE
};

typedef struct s_convertion_table
{
	int				i;
	float			f;
	double			d;
	std::string		c_str;
	std::string		i_str;
	std::string		f_str;
	std::string		d_str;
}	t_conv_tab;

#endif