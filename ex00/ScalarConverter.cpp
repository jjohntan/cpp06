/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:59:23 by jetan             #+#    #+#             */
/*   Updated: 2025/06/27 22:54:55 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void displaydouble(double d)
{
	std::cout << "double: " << d;
	if (d == d)
		std::cout << ".0";
	std::cout << std::endl;
}

static void displayfloat(float f)
{
	std::cout << "float: " << f;
	if (f == f)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

static void displaychar(char c)
{
	if (c < 0 || c > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << c << "'" << std::endl;
}

static bool checkNumeric(std::string literal)
{
	int countDot = 0;
	int countSign = 0;
	int countF = 0;
	bool hasdigit = false;
	
	for (unsigned int i = 0; i < literal.length(); i++)
	{
		if (literal[i] == '.')
			countDot++;
		else if (literal[i] == '+' || literal[i] == '-')
		{
			if (i != 0)//check if sign not at start
				return false;
			countSign++;
		}
		else if (literal[i] == 'f')
			countF++;
		else if (std::isdigit(literal[i]))
			hasdigit = true;
		else
			return false;
	}
	if (countDot > 1 || countSign > 1)//make sure '.' or sign only contain one
		return false;
	if (countF == 1 && literal[literal.length() - 1] != 'f')//make sure f only at the end
		return false;
	if (!hasdigit)//make sure only contain digit
		return false;
	return true;
}

static int detectType(std::string literal) 
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return FLOAT;
	if (literal == "-inf" || literal == "+inf" || literal == "nan" )
		return DOUBLE;
	if (literal.length() == 1 && !std::isdigit(literal[0]))//check the string length is equals to one
		return CHAR;
	if (checkNumeric(literal))
		return INT;
	if (literal[literal.length() - 1] == 'f' && checkNumeric(literal))
		return FLOAT;
	if (literal.find('.') && checkNumeric(literal))
		return DOUBLE;
	return ERROR;
}

void ScalarConverter::convert(std::string literal)
{
	switch (detectType(literal))
	{
		case CHAR:
		{
			char c = literal[0];
			int n = static_cast<int>(c);
			float f = static_cast<float>(c);
			double d = static_cast<double>(c);
			
			displaychar(c);
			std::cout << "int: " << n << std::endl;
			displayfloat(f);
			displaydouble(d);
			break;
		}
		case INT:
		{
			int n = std::atoi(literal.c_str());
			char c = static_cast<char>(n);
			float f = static_cast<float>(n);
			double d = static_cast<double>(n);
			
			displaychar(c);
			std::cout << "int: " << n << std::endl;
			displayfloat(f);
			displaydouble(d);
			break;
		}
		case FLOAT:
		{
			float f = std::strtof(literal.c_str(), 0);
			char c = static_cast<char>(f);
			int n = static_cast<int>(f);
			double d = static_cast<double>(f);
			
			displaychar(c);
			std::cout << "int: " << n << std::endl;
			displayfloat(f);
			displaydouble(d);
			break;
		}
		case DOUBLE:
		{
			double d = std::strtod(literal.c_str(), 0);
			char c = static_cast<char>(d);
			int n = static_cast<int>(d);
			float f = static_cast<float>(d);
			
			displaychar(c);
			std::cout << "int: " << n << std::endl;
			displayfloat(f);
			displaydouble(d);
			break;
		}
	}
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