/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:59:23 by jetan             #+#    #+#             */
/*   Updated: 2025/06/30 14:40:08 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void displaydouble(double d)
{
	std::cout << "double: " << d;
	if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << std::endl;
}

static void displayfloat(float f)
{
	std::cout << "float: " << f;
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

/**
 * @brief compare to int min and max, if overflow print impossible
 * else type cast and print out the value
 */
static void displayint(double d)
{
	//-inff, +inff, nanf, -inf, +inf and nan is a special floating-point value defined by the IEEE 754 standard
	//Any comparison with the standard is false, even comparing it to itself.
	if (d != d || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
}

static void displaychar(double d)
{
	int n = static_cast<int>(d);
	
	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(n))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(d) << "'" << std::endl;
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
			float f = static_cast<float>(c);
			double d = static_cast<double>(c);
			
			displaychar(d);
			std::cout << "int: " << static_cast<int>(c) << std::endl;
			displayfloat(f);
			displaydouble(d);
			break;
		}
		case INT:
		{
			//reason why not using atoi, if the string value is bigger than INT_MAX,
			//it will causes undefined behavior
			double d = std::strtod(literal.c_str(), 0);
			float f = static_cast<float>(d);
			
			displaychar(d);
			displayint(d);
			displayfloat(f);
			displaydouble(d);
			break;
		}
		case FLOAT:
		{
			float f = std::strtof(literal.c_str(), 0);
			double d = static_cast<double>(f);
			
			displaychar(d);
			displayint(d);
			displayfloat(f);
			displaydouble(d);
			break;
		}
		case DOUBLE:
		{
			double d = std::strtod(literal.c_str(), 0);
			float f = static_cast<float>(d);
			
			displaychar(d);
			displayint(d);
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