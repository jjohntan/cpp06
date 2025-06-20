/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:45:08 by jetan             #+#    #+#             */
/*   Updated: 2025/06/20 15:40:34 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class D: public Base
{
	
};

int main()
{
	A a;
	B b;
	C c;
	D d;
	
	identify(&a);
	identify(a);
	identify(&b);
	identify(b);
	identify(&c);
	identify(c);
	identify(&d);
	identify(d);
}