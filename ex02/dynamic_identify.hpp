/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_identify.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:40:40 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/24 22:12:25 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNAMIC_IDENTIFY_HPP
# define DYNAMIC_IDENTIFY_HPP

# include <iostream>
# include <random>

class Base
{
	public:
		virtual ~Base(void);
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

#endif
