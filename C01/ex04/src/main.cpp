/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:26:05 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/03 20:45:54 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	size_t found = 0;
	size_t before = 0;
	std::string line;
	std::ifstream in_file;
	std::ofstream out_file;

	if (argc != 4)
	{
		std::cout << "Number of arguments incorrect!" << std::endl;
		return (0);
	}
	in_file.open(argv[1], std::ios::in);
	if (!in_file.good())
	{
		std::cout << "File doens't exist or it is without permissions!" << std::endl;
		return (1);
	}
	getline(in_file, line, (char)EOF);
	in_file.close();

	out_file.open(argv[1], std::ios::out | std::ios::trunc);
	while ((found = line.find(argv[2], before)) != std::string::npos)
	{
		for (size_t i = before; i < found; i++)
			out_file << line[i];
		out_file << argv[3];
		before = found + strlen(argv[2]);
	}
	std::cout << "Before: " << before << " length: " << line.length() << std::endl;
	for (size_t i = before; i < line.length(); i++)
		out_file << line[i];
	out_file.close();
}
