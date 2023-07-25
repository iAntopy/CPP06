/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caster.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:47:52 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/24 19:02:27 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTING_HPP
# define CASTING_HPP

# include <iostream>
# include <string>
# include <sstream>
//# include <limits>

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