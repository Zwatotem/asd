#include "HeapSorter.h"

using std::vector;

template <typename T>
HeapSorter<T>::HeapSorter(vector<T> array) : Sorter<T>(array)
{
	heapSize = array.size();
}

template <typename T>
void HeapSorter<T>::sort()
{
	old_array = array;
	buildHeap(0, array.size());
	for (; heapSize > 2; heapSize--)
	{
		heapSortIteration(heapSize - 1);
	}
}


template <typename T>
void HeapSorter<T>::buildHeap(int start, int size)
{
	for (int i = (size - start) / 2; i >= start; i--)
	{
		heapify(i);
	}
	heapSize = size;
}

template <typename T>
void HeapSorter<T>::heapify(int position)
{
	if (position > heapSize / 2 - 2)
	{
		return;
	}
	if (left(position) > array[position] || r(position) > 0 && right(position) > array[position])
	{
		int max = left(position);
		int maxpos = l(position);
		if (r(position) > 0 && left(position) < right(position))
		{
			max = right(position);
			maxpos = r(position);
		}
		std::swap(array[position], array[maxpos]);
		heapify(maxpos);
	}
}

template <typename T>
void HeapSorter<T>::heapSortIteration(int n)
{
	std::swap(array[0], array[n]);
	heapify(0);
}
