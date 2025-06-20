/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:47:36 by jetan             #+#    #+#             */
/*   Updated: 2025/06/20 20:50:23 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/**
 * reference type can't return a null reference
 */
void identify(Base& p)
{
	try
	{
		A &ap = dynamic_cast<A&>(p);
		(void)ap;
		std::cout << "A" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B &bp = dynamic_cast<B&>(p);
		(void)bp;
		std::cout << "B" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C &cp = dynamic_cast<C&>(p);
		(void)&cp;
		std::cout << "C" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
	}
	std::cout << "Unknown pointer!" << std::endl;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "C" << std::endl;
	}
	else
	{
		std::cout << "Unknown reference!" << std::endl;
	}
}

Base * generate(void)
{
	srand(time(NULL));
	
	int num = (std::rand() % 3);//Generate random number
	
	switch (num)
	{
	case 0:
		return new A;
		break;
	case 1:
		return new B;
		break;
	case 2:
		return new C;
		break;
	default:
		std::cout << "Unknown type!" << std::endl;
		break;
	}
	return NULL;
}

Base::~Base()
{
	std::cout << "Base destructor called" << std::endl;
}