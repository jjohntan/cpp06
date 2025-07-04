/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:59:20 by jetan             #+#    #+#             */
/*   Updated: 2025/06/28 15:39:38 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
# define SCALARCONVERTER

#include <iostream>
#include <cctype>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <limits>

//An enum is a special type that represents a group of constants (unchangeable values)
enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	ERROR
};

class ScalarConverter
{
	//As this class doesn’t need to store anything at all, this class must not be instanciable by users
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
	public:
		static void convert(std::string literal);
};

#endif