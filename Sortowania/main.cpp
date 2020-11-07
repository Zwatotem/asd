// InsertionSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "InsertionSorter.cpp"
#include "MergeSorter.cpp"
#include "HeapSorter.cpp"

int main()
{
	vector<int> arr1{
		-1,-1,3,4,77,2,18,-15,-4,-3,5,5,2,7,-4,4
	};
	InsertionSorter<int> isorter(arr1);
	MergeSorter<int> msorter(arr1);
	HeapSorter<int> hsorter(arr1);
	isorter.sort();
	msorter.sort();
	hsorter.sort();
	isorter.Sorter<int>::print();
	msorter.Sorter<int>::print();
	hsorter.Sorter<int>::print();
	std::cout << isorter.verify() << std::endl;
	std::cout << msorter.verify() << std::endl;
	std::cout << hsorter.verify() << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
