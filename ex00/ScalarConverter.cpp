/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:59:23 by jetan             #+#    #+#             */
/*   Updated: 2025/06/25 20:15:16 by jetan            ###   ########.fr       */
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
		
			std::cout << "char: " << c << std::endl;
			int n = static_cast<int>(c);
			float f = static_cast<float>(c);
			double d = static_cast<double>(c);
			
			std::cout << "int: " << n << std::endl;
			std::cout << "float: " << f << ".0f" << std::endl;
			std::cout << "double: " << d << ".0" << std::endl;
			break;
		}
		case INT:
		{
			int n = std::atoi(literal.c_str());
			char c = static_cast<char>(n);
			float f = static_cast<float>(n);
			double d = static_cast<double>(n);
			
			std::cout << "char: " << c << std::endl;
			std::cout << "int: " << n << std::endl;
			std::cout << "float: " << f << ".0f" << std::endl;
			std::cout << "double: " << d << ".0" << std::endl;
			break;
		}
		case FLOAT:
		{
			float f = std::strtof(literal.c_str(), 0);
			char c = static_cast<char>(f);
			int n = static_cast<float>(f);
			double d = static_cast<double>(f);
			
			std::cout << "char: " << c << std::endl;
			std::cout << "int: " << n << std::endl;
			std::cout << "float: " << f;
			if (f == f)
				std::cout << ".0";
			std::cout << "f" << std::endl;
			std::cout << "double: " << d;
			if (d == d)
				std::cout << ".0";
			std::cout << std::endl;
			break;
		}
		case DOUBLE:
		{
			double d = std::strtod(literal.c_str(), 0);
			char c = static_cast<char>(d);
			int n = static_cast<float>(d);
			float f = static_cast<float>(d);
			
			std::cout << "char: " << c << std::endl;
			std::cout << "int: " << n << std::endl;
			std::cout << "float: " << f;
			if (f == f)
				std::cout << ".0";
			std::cout << "f" << std::endl;
			std::cout << "double: " << d;
			if (d == d)
				std::cout << ".0";
			std::cout << std::endl;
			break;
		}
		// case PSEUDO:
		//{	
		// 	break;
		//}
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
		return INT;
	if (literal[literal.length() - 1] == 'f')
		return FLOAT;
	if (literal[literal.length() - 1] != 'f')
		return DOUBLE;
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return FLOAT;
	if (literal == "-inf" || literal == "+inf" || literal == "nan" )
		return DOUBLE;
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