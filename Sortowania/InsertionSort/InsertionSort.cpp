// InsertionSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sorter.cpp"

int main()
{
	vector<int> arr1{
		-1,-1,3,4,77,2,18,-15,-4,-3,5,5,2,7,-4,4
	};
	Sorter<int> sorter(arr1);
	sorter.sort();
	sorter.print();
	std::cout << sorter.verify() << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
