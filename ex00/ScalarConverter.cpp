/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:59:23 by jetan             #+#    #+#             */
/*   Updated: 2025/06/24 21:13:01 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string literal)
{
	switch (detectType(literal))
	{
		case CHAR:
		{
			char c = literal[0];
			// if (c )
			// {
				
			// }
			int i = static_cast<int>(c);
			float f = static_cast<float>(c);
			double d = static_cast<double>(c);
			
			std::cout << c << std::endl;
			std::cout << i << std::endl;
			std::cout << f << ".0f" << std::endl;
			std::cout << d << ".0" << std::endl;
			break;
		}
		// case INT:
			
		// 	break;
		// case FLOAT:
			
		// 	break;
		// case DOUBLE:
			
		// 	break;
		// case PSEUDO:
			
		// 	break;
	}
}

static bool isInt(std::string literal)
{
	for (unsigned int i = 0; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]))
			return false;
	}
	return true;
}

int detectType(std::string literal) 
{
	if (literal.length() == 1 && !isdigit(literal[0]))//check the string length is equals to one
		return CHAR;
	if (isInt(literal))
		std::cout << "Int" << std::endl;
	// if (literal[literal.length() - 1] == 'f')
	// 	std::cout << "Float" << std::endl;
	// if ()
	// 	std::cout << "Double" << std::endl;
	return ERROR;
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