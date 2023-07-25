/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:08:51 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/24 21:10:44 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

typedef struct s_data
{
	int				x;
	float			y;
	struct s_data	*next;	
}   Data;

uintptr_t   serialize(Data* ptr);
Data*		deserialize(uintptr_t ptr);

#endif