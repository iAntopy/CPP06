/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:02:11 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/24 21:18:32 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

int main()
{
	Data	d1 = {999, 999.99f, NULL};
	Data	d2 = {42, 99.99f, &d1};
	Data	d3 = {-1000, 420.42f, &d2};

	std::cout << "d1.x : " << d3.next->next->x << std::endl;
	std::cout << "d1.y : " << d3.next->next->y << std::endl;
	std::cout << "d1.next ptr : " << d3.next->next->next << std::endl;

	uintptr_t	serialized_p = serialize(&d3);
	
	std::cout << "serialized_p in uintptr_t :	" << serialized_p << std::endl;
	std::cout << "serialized_p in hexa :		" << (void *)serialized_p << std::endl;

	Data*		deserialized_p = deserialize(serialized_p);

	std::cout << "deserialized_p in uintptr_t :	" << deserialized_p << std::endl;

	std::cout << "d1.x : " << deserialized_p->next->next->x << std::endl;
	std::cout << "d1.y : " << deserialized_p->next->next->y << std::endl;
	std::cout << "d1.next ptr : " << deserialized_p->next->next->next << std::endl;
	
	return (0);
}