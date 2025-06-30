/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:26:22 by jetan             #+#    #+#             */
/*   Updated: 2025/06/30 17:11:37 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;
	Data *data_ptr;
	
	data.num = 42;
	
	uintptr_t raw = Serializer::serialize(&data);
	data_ptr = Serializer::deserialize(raw);
	
	std::cout << "value of data: " << data.num << std::endl;
	std::cout << "raw: " << raw << std::endl;
	std::cout << "address of data: " << &data << std::endl;
	std::cout << "value of data pointer: " << data_ptr->num << std::endl;
	std::cout << "address of data pointer: " << data_ptr << std::endl;
	
	//compare
	if (data_ptr == &data)
		std::cout << "valid" << std::endl;
	else
		std::cout << "invalid" << std::endl;
}