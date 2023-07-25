/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:40:40 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/24 22:31:00 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_identify.hpp"

Base*	generate(void)
{
	static std::random_device	rd;
	int							pick;

	pick = rd() % 3;
	switch (pick)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());

	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << 'A' << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << 'B' << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << 'C' << std::endl;
	else
		std::cerr << "Unidentifiable" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A&	a = dynamic_cast<A&>(p);
		std::cout << 'A' << std::endl;
		return ;
	}
	catch (std::bad_cast &e) {}
	try
	{
		B&	b = dynamic_cast<B&>(p);
		std::cout << 'B' << std::endl;
		return ;
	}
	catch (std::bad_cast &e) {}
	try
	{
		C&	c = dynamic_cast<C&>(p);
		std::cout << 'C' << std::endl;
		return ;
	}
	catch (std::bad_cast &e) {}
}

int	main()
{
	Base	*inst;

	inst = generate();
	identify(inst);
	identify(*inst);
	delete inst;
	return (0);
}