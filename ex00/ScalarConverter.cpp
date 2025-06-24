/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:59:23 by jetan             #+#    #+#             */
/*   Updated: 2025/06/24 15:36:00 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string literal)
{
	
}

// bool isFloat(std::string literal)
// {
	
// }

static bool isInt(std::string literal)
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
	if (literal.length() == 1 && isprint(literal[0]))//check the string length is equals to one
		std::cout << "Char" << std::endl;
	if (!isInt(literal))
		std::cout << "Int" << std::endl;
	if (literal[literal.length() - 1] == 'f')
		std::cout << "Float" << std::endl;
	// if ()
	// 	std::cout << "Double" << std::endl;
}

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "ScalarConverter Copy constructor called" << std::endl;
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "ScalarConverter Copy assignment operator called " << std::endl;
	(void)other;
	return *this;
}