/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:11:27 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/24 19:14:54 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

uintptr_t   serialize(Data* ptr)
{
	uintptr_t	cast_ptr = reinterpret_cast<uintptr_t>(ptr);

	return (cast_ptr);
}

Data*	deserialize(uintptr_t ptr)
{
	Data*	ori_ptr = reinterpret_cast<Data *>(ptr);
	
	return (ori_ptr);
}
