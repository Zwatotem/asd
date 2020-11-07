#include "HeapSorter.h"

using std::vector;

template <typename T>
HeapSorter<T>::HeapSorter(vector<T> array)
{
	this->array = array;
	heapSize = array.size();
}

template <typename T>
void HeapSorter<T>::sort()
{
	old_array = array;
	buildHeap(0, array.size());
	print();
	for (; heapSize > 2; heapSize--)
	{
		heapSort(heapSize - 1);
		print();
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
	// print();
}

template <typename T>
void HeapSorter<T>::heapSort(int n)
{
	std::swap(array[0], array[n]);
	heapify(0);
}
template <typename T>
vector<T> HeapSorter<T>::get()
{
	return array;
}

template <typename T>
void HeapSorter<T>::set(vector<T> new_array)
{
	array = new_array;
	heapSize = array.size();
}

template <typename T>
void HeapSorter<T>::print()
{
	using std::cout;
	using std::endl;
	cout << "(";
	for (auto i : array)
	{
		cout << i << ", ";
	}
	cout << "\b\b)" << endl;
}

template <typename T>
bool HeapSorter<T>::verify()
{
	for (auto i = 0; i < array.size() - 1; i++)
	{
		if (array[i + 1] < array[i])
		{
			return false;
		}
	}
	int count = 0;
	for (auto i = 0; i < array.size(); i++)
	{
		if (i == array.size() - 1 || array[i] != array[i + 1])
		{
			count++;
			auto searched = array[i];
			auto old_count = 0;
			for (auto j = 0; j < old_array.size(); j++)
			{
				if (old_array[j] == searched)
				{
					old_count++;
				}
			}
			if (old_count != count)
			{
				return false;
			}
			count = 0;
		}
		else
		{
			count++;
		}
	}
	return true;
}