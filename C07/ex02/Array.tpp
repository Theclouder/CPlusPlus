#include "Array.hpp"

template<class T>
Array<T>::Array()
{
	this->_size = 0;
	this->_arr = new T[0];
	std::cout << YELLOW << "Array default constructor!" << RESET << std::endl;
}

template<class T>
Array<T>::Array(unsigned int n)
{
	this->_size = n - 1;
	this->_arr = new T[n];
	for (unsigned int i = 0; i < n; i++)
		this->_arr[i] = '\0';
	std::cout << MAGENTA << "Array custom constructor!" << RESET << std::endl;
}

template<class T>
Array<T>::Array(const Array & rhs)
{
	*this = rhs;
	std::cout << BLUE << "Array copy constructor!" << RESET << std::endl;
}

template<class T>
Array<T>& Array<T>::operator=(const Array & rhs)
{
	this->_size = rhs._size;
	this->_arr = new T[rhs._size];
	for (unsigned int i = 0; i < rhs._size; i++)
		this->_arr[i] = rhs._arr[i];
	std::cout << CYAN << "Array operator assignment!" << RESET << std::endl;
	return *this;
}

template<class T>
Array<T>::~Array()
{
	delete [] this->_arr;
}

template<class T>
unsigned int Array<T>::size() const
{
	return this->_size;
}

template<class T>
const char *Array<T>::outOfBoundsException::what() const throw() { return RED "Index out of range" RESET; }

template<class T>
T& Array<T>::operator[](unsigned int i)
{
	if (i > this->_size)
		throw Array<T>::outOfBoundsException();
	return this->_arr[i];
}

