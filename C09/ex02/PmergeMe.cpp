/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:46:27 by vduchi            #+#    #+#             */
/*   Updated: 2024/02/23 13:51:49 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & rhs)
{
	*this = rhs;
}

PmergeMe& PmergeMe::operator=(const PmergeMe & rhs)
{
	this->_v = rhs._v;
	this->_l = rhs._l;
	return *this;
}

PmergeMe::~PmergeMe() {}

int PmergeMe::getListEl(std::list<int> & l, int i)
{
	std::list<int>::iterator it = l.begin();
    for(int k = 0; k < i; k++){
        ++it;
    }
    return *it;
}

void PmergeMe::setListEl(std::list<int> & l, int i, int val)
{
	std::list<int>::iterator it = l.begin();
    for(int k = 0; k < i; k++){
        ++it;
    }
	*it = val;
}

void PmergeMe::listMerge(std::list<int> & l, int low, int mid, int high) {

	int lengthLeft = mid - low + 1;
	int lengthRight = high - mid;
	std::vector<int> arrLeft(lengthLeft);
	std::vector<int> arrRight(lengthRight);

	for (int i = 0; i < lengthLeft; i++) {
		arrLeft[i] = this->getListEl(l, low + i);
	}
	for (int i = 0; i < lengthRight; i++) {
		arrRight[i] = this->getListEl(l, mid + 1 + i);
	}
	int i = 0, j = 0, k = low;
	while (i < lengthLeft && j < lengthRight) {
		if (arrLeft[i] <= arrRight[j])
			this->setListEl(l, k++, arrLeft[i++]);
		else
			this->setListEl(l, k++, arrRight[j++]);
	}
	while (i < lengthLeft) {
		this->setListEl(l, k++, arrLeft[i++]);
	}
	while (j < lengthRight) {
		this->setListEl(l, k++, arrRight[j++]);
	}
}

void PmergeMe::listMergeSort(std::list<int> & l, int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high) {
        this->listMergeSort(l, low, mid);
        this->listMergeSort(l, mid + 1, high);
        this->listMerge(l, low, mid, high);
    }
}

void PmergeMe::vecMerge(std::vector<int> & v, int low, int mid, int high) {

    int lengthLeft = mid - low + 1;
    int lengthRight = high - mid;
	std::vector<int> arrLeft(lengthLeft);
	std::vector<int> arrRight(lengthRight);

    for (int i = 0; i < lengthLeft; i++) {
        arrLeft[i] = v[low + i];
    }
    for (int i = 0; i < lengthRight; i++) {
        arrRight[i] = v[mid + 1 + i];
    }
    int i = 0, j = 0, k = low;
    while (i < lengthLeft && j < lengthRight) {
        if (arrLeft[i] <= arrRight[j])
            v[k++] = arrLeft[i++];
        else
            v[k++] = arrRight[j++];
    }
    while (i < lengthLeft) {
        v[k++] = arrLeft[i++];
    }
    while (j < lengthRight) {
        v[k++] = arrRight[j++];
    }
}

void PmergeMe::vecMergeSort(std::vector<int> & v, int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high) {
        this->vecMergeSort(v, low, mid);
        this->vecMergeSort(v, mid + 1, high);
        this->vecMerge(v, low, mid, high);
    }
}

void PmergeMe::startListAlgorithm(char *argv[])
{
//	gettimeofday(&this->_beginL, 0);
	this->_beginL = clock();
	for (int i = 1; argv[i] != NULL; i++)
		this->_l.push_back(atoi(argv[i]));
	this->listMergeSort(this->_l, 0, this->_l.size() - 1);
	this->_endL = clock();
//	gettimeofday(&this->_endL, 0);
}

void PmergeMe::startVectorAlgorithm(char *argv[])
{
//	gettimeofday(&this->_beginV, 0);
	this->_beginV = clock();
	for (int i = 1; argv[i] != NULL; i++)
		this->_v.push_back(atoi(argv[i]));
	this->vecMergeSort(this->_v, 0, this->_v.size() - 1);
	this->_endV = clock();
//	gettimeofday(&this->_endV, 0);
}

void PmergeMe::printET(char *argv[])
{
	std::cout << "Before:\t";
	for  (int i = 1; argv[i] != NULL; i++)
	{
		std::cout << argv[i];
		if (argv[i + 1] != NULL)
			std::cout << " ";
	}
	std::cout << std::endl << "After:\t";
	for  (std::list<int>::iterator it = this->_l.begin(); it != this->_l.end(); it++)
	{
		std::cout << *it;
		std::list<int>::iterator it2 = it;
		it2++;
		if (it2 != this->_l.end())
			std::cout << " ";
	}
	std::cout << std::endl;
	double lTime = (double)(this->_endL - this->_beginL) / CLOCKS_PER_SEC;
	double vTime = (double)(this->_endV - this->_beginV) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << this->_l.size() << " elements with std::list   : ";
	std::cout << std::fixed << std::setprecision(6) << lTime << " s" << std::endl;
	std::cout << "Time to process a range of " << this->_v.size() << " elements with std::vector : ";
	std::cout << std::fixed << std::setprecision(6) << vTime << " s" << std::endl;
}
