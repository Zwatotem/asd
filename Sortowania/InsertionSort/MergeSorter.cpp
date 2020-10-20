#include "MergeSorter.h"

using std::vector;

template <typename T>
MergeSorter<T>::MergeSorter(vector<T> array)
{
	this->array = array;
}

template <typename T>
void MergeSorter<T>::sort()
{
	merge_sort(0, array.size() - 1);
}

template <typename T>
void MergeSorter<T>::merge_sort(int start, int end)
{
	old_array = array; // Saving for verification
	if (end > start)
	{
		auto mid = (start + end) / 2;
		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		merge(start, mid, end);
	}
}
template <typename T>
void MergeSorter<T>::merge(int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	vector<T> v;
	int k = 0;
	while (i <= mid || j <= end)
	{
		while (i <= mid && j <= end)
		{
			if (array[i] < array[j])
			{
				v.push_back(array[i]);
				k++;
				i++;
			}
			else
			{
				v.push_back(array[j]);
				k++;
				j++;
			}
		}
		while (i <= mid)
		{
			v.push_back(array[i]);
			k++;
			i++;
		}
		while (j <= end)
		{
			v.push_back(array[j]);
			k++;
			j++;
		}
	}
	for (auto i = start, k = 0; i <= end; i++, k++)
	{
		array[i] = v[k];
	}
}

template <typename T>
vector<T> MergeSorter<T>::get()
{
	return array;
}

template <typename T>
void MergeSorter<T>::set(vector<T> new_array)
{
	array = new_array;
}

template <typename T>
void MergeSorter<T>::print()
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
bool MergeSorter<T>::verify()
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