/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:28:45 by jetan             #+#    #+#             */
/*   Updated: 2025/06/12 18:31:18 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

/**
 * uintptr_t is a unsigned integer that is large enough to hold any pointer value
 */
class Serializer
{
	private:
		Serializer();
		~Serializer();
	public:
	static uintptr_t serialize(Data* ptr);//static method
	static Data* deserialize(uintptr_t raw);//static method
};

#endif