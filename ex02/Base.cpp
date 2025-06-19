/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:47:36 by jetan             #+#    #+#             */
/*   Updated: 2025/06/19 18:43:25 by jetan            ###   ########.fr       */
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
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B &bp = dynamic_cast<B&>(p);
		(void)bp;
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C &cp = dynamic_cast<C&>(p);
		(void)&cp;
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	std::cout << "Unknown" << std::endl;
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
		std::cout << "Unknown" << std::endl;
	}
}

// Base * generate(void)
// {
	
// }

Base::~Base()
{
	std::cout << "Base destructor called" << std::endl;
}