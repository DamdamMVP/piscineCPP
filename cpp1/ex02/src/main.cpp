/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damdam <damdam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:35:54 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/19 19:01:04 by damdam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address of the string variable    : " << &str << std::endl;
	std::cout << "Address held by stringPTR         : " << stringPTR << std::endl;
	std::cout << "Address of stringREF              : " << &stringREF << std::endl;

	std::cout << "Value of the string variable      : " << str << std::endl;
	std::cout << "Value pointed to by stringPTR     : " << *stringPTR << std::endl;
	std::cout << "Value referenced by stringREF     : " << stringREF << std::endl;

	return 0;
}