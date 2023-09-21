/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:26:05 by vduchi            #+#    #+#             */
/*   Updated: 2023/09/21 20:19:36 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	size_t found = 0;
	size_t before = 0;
	std::string line;
	std::string newName;
	std::ifstream inFile;
	std::ofstream outFile;

	if (argc != 4)
	{
		std::cout << "Number of arguments incorrect!" << std::endl;
		return (0);
	}
	inFile.open(argv[1], std::ios::in);
	if (!inFile.good())
	{
		std::cout << "File " << argv[1] << " doesn't exist or it is without permissions!" << std::endl;
		return (1);
	}
	getline(inFile, line, (char)EOF);
	inFile.close();

	outFile.open(std::string(argv[1]) + ".replace", std::ios::out | std::ios::trunc);
	while ((found = line.find(argv[2], before)) != std::string::npos)
	{
		for (size_t i = before; i < found; i++)
			outFile << line[i];
		outFile << argv[3];
		before = found + strlen(argv[2]);
	}
	for (size_t i = before; i < line.length(); i++)
		outFile << line[i];
	outFile.close();
}
