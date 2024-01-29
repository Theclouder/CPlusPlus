/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:15:51 by vduchi            #+#    #+#             */
/*   Updated: 2024/01/29 17:27:36 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
//
// Function to merge the sub-arrays.
void merge(std::vector<int> & v, int low, int mid, int high) {
    int i, j, k;
    int lengthLeft = mid - low + 1;
    int lengthRight = high - mid;

    // Creating two temp arrays to store left and right sub-arrays.
//    int arrLeft[lengthLeft], arrRight[lengthRight];
	std::vector<int> arrLeft(lengthLeft);
	std::vector<int> arrRight(lengthRight);

    // Copying the data from the actual array to left and right temp arrays.
    for (int a = 0; a < lengthLeft; a++) {
        arrLeft[a] = v[low + a];
    }
    for (int a = 0; a < lengthRight; a++) {
        arrRight[a] = v[mid + 1 + a];
    }

    // Merging the temp arrays back into the actual array.
    i = 0; // Starting index of arrLeft[].
    j = 0; // Staring index of arrRight[].
    k = low; // Starting index of merged subarray.

    while (i < lengthLeft && j < lengthRight) {
        // Checking and placing the smaller number of both temp arrays into the main array.
        if (arrLeft[i] <= arrRight[j]) {
            v[k] = arrLeft[i];
            i++;
        } else {
            v[k] = arrRight[j];
            j++;
        }
        k++;
    }

    // After the successful execution of the above loop
    // copying the remaining elements of the left subarray (if remaining).
    while (i < lengthLeft) {
        v[k] = arrLeft[i];
        k++;
        i++;
    }

    // Copying the remaining elements of the right sub array (if remaining).
    while (j < lengthRight) {
        v[k] = arrRight[j];
        k++;
        j++;
    }
}

// The mergeSort() function.
void mergeSort(std::vector<int> & v, int low, int high) {
    int mid;
    if (low < high) {
        // Calculating the mid.
        mid = (low + high) / 2;

        // Calling the function mergeSort() recursively and breaking down the given array into smaller sub arrays.
        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);

        // Calling the merge() function to merge the sorted subarrays into the main array.
        merge(v, low, mid, high);
    }
}


int checkInput(char *argv[], std::vector<int> & v)
{
	try {
		for (int i = 1; argv[i] != NULL; i++)
			for (int l = 0; argv[i][l] != '\0'; l++)
				if (!isdigit(argv[i][l]))
					throw std::invalid_argument("one of the arguments is not an int!");
		for (int i = 1; argv[i] != NULL; i++)
			v.push_back(atoi(argv[i]));
//		std::cout << YELLOW << "Vector values: ";
//		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
//			std::cout << *it << " ";
//		std::cout << RESET << std::endl;
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			std::vector<int>::iterator it2 = it;
			it2++;
			for (; it2 != v.end(); it2++)
				if (*it2 == *it)
					throw std::invalid_argument("one of the integers is repeated!");
		}
	}
	catch (std::exception & ex) { std::cout << RED << "Error => " << ex.what() << RESET << std::endl; return 1; }
	return 0;
}

int main(int argc, char *argv[])
{
	std::vector<int> v;
	if (argc == 1)
	{
		std::cout << ORANGE << "The program needs at least one argument!";
		std::cout << RESET << std::endl;
		return 1;
	}
	else if (checkInput(argv, v))
		return 1;
	try {
		PmergeMe pmm;
		pmm.addList(v);
		int l = 0;
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			l++;
//		int *arr = new int[l];
//		l = 0;
//		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
//			arr[l] = *it;
		mergeSort(v, 0 , l - 1);
		std::cout << GREEN << "New values: ";
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout  << *it << " ";
		std::cout << RESET << std::endl;
//		for (int i = 1; argv[i] != NULL; i++)
//			v.push_back(atoi(argv[i]));
	}
	catch (std::exception & ex) { std::cout << RED << ex.what() << RESET << std::endl; }
}
