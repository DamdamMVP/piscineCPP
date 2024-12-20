/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 03:19:27 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/20 03:57:15 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

void	replaceStrings(const std::string &filename, const std::string &s1,
		const std::string &s2)
{
	size_t	pos;

	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return ;
	}
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Error: Could not create output file " << filename << ".replace" << std::endl;
		return ;
	}
	std::string line;
	while (std::getline(infile, line))
	{
		while ((pos = line.find(s1)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
		}
		outfile << line << std::endl;
	}
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "./zombie 'filename' 's1' 's2'" << std::endl;
		return (1);
	}

	const std::string filename = av[1];
	const std::string s1 = av[2];
	const std::string s2 = av[3];

	if (filename.empty())
	{
		std::cout << "filename can't be empty." << std::endl;
		return (2);
	}
	if (s1.empty())
	{
		std::cout << "s1 can't be empty." << std::endl;                                                                                                                                                                                                                                                                                                              
		return (3);
	}

	replaceStrings(filename, s1, s2);
	return (0);
}