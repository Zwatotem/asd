#pragma once
#include <vector>
#include <iostream>
#include "Sorter.h"
using std::vector;
template <typename T>
class HeapSorter : public Sorter<T>
{	
    using Sorter<T>::array;
    using Sorter<T>::old_array;
	
private:
	int heapSize;
	void buildHeap(int start, int end);
	void heapify(int position);
	int l(int nodeN) { return (2 * nodeN + 1) < array.size() ? (2 * nodeN + 1) : -1; };
	int r(int nodeN) { return (2 * nodeN + 2) < array.size() ? (2 * nodeN + 2) : -1; };
	int p(int nodeN) { return (nodeN / 2 - 1) < array.size() ? (nodeN / 2 - 1) : -1; };
	int left(int nodeN) { return array[(2 * nodeN + 1)]; };
	int right(int nodeN) { return array[(2 * nodeN + 2)]; };
	int parent(int nodeN) { return array[(nodeN / 2 - 1)]; };
	void heapSortIteration(int n);
public:
	HeapSorter(vector<T> array);

    virtual void sort() override;
};

