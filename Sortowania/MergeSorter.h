#pragma once
#include <vector>
#include <iostream>
#include "Sorter.cpp"
using std::vector;
template <typename T>
class MergeSorter : public Sorter<T>
{
	using Sorter<T>::array;
	using Sorter<T>::old_array;

private:
	void merge_sort(int start, int end);
	void merge(int start, int mid, int end);

public:
	MergeSorter(vector<T> array);

	virtual void sort() override;
};
