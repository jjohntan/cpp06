/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:59:23 by jetan             #+#    #+#             */
/*   Updated: 2025/06/23 10:42:50 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isNumber(std::string literal)
{
	for (unsigned int i = 0; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]))
			return false;
	}
	return true;
}

void detectType(std::string literal)
{
	if (literal.length() == 1)//check the string length is equals to one
		std::cout << "Char" << std::endl;
	if (!isNumber(literal))
		std::cout << "Int" << std::endl;
}