/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:11:29 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/23 21:24:25 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _idx(0)
{
	for (int i = 0; i < 4; i++)
		this->_mat[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
	*this = other;
}

MateriaSource& MateriaSource::operator=(MateriaSource const & other)
{
	this->_idx = other._idx;
	for (int i = 0; i < 4; i++)
	{
		if (this->_mat[i] != NULL)
		{
			delete this->_mat[i];
			this->_mat[i] = NULL;
		}
		if (other._mat[i] != NULL)
			this->_mat[i] = other._mat[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (this->_mat[i] != NULL)
			delete this->_mat[i];
}

void MateriaSource::learnMateria(AMateria* mat)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_mat[i] != NULL && this->_mat[i]->getType().compare(mat->getType()) == 0)
		{
			std::cout << "Already have this type of Materia!" << std::endl;
			delete mat;
			return ;
		}
	}
	if (this->_idx + 1 > 3)
	{
		std::cout << "Too many materials learnt!" << std::endl;
		delete mat;
		return ;
	}
	this->_mat[this->_idx] = mat;
	this->_idx += 1;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_mat[i] != NULL)
		{
			if (this->_mat[i]->getType().compare(type) == 0)
				return this->_mat[i]->clone();
		}
	}
	return NULL;
}
