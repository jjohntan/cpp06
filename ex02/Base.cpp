/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:47:36 by jetan             #+#    #+#             */
/*   Updated: 2025/06/17 18:31:39 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate(void)
{
	
}

void identify(Base* p)
{
	if ()
	{
		std::cout << "A" << std::endl;
	}
	else if ()
	{
		std::cout << "B" << std::endl;
	}
	else if ()
	{
		std::cout << "C" << std::endl;
	}
	else
	{
		std::cout << "No such type" << std::endl;
	}
}

/**
 * reference type can't return a null reference
 */
void identify(Base& p)
{
	try
	{
		
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}
