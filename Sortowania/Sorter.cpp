#include "Sorter.h"

using std::vector;

template<typename T>
Sorter<T>::Sorter(vector<T> array)
{
	this->array = array;
}

template<typename T>
void Sorter<T>::sort()
{
	old_array = array;
	auto n = array.size();
	for (auto j = 0; j < n; j++)
	{
		auto element = array[j];
		auto i = j - 1;
		while (i >= 0 && array[i] > element)
		{
			array[i + 1] = array[i];
			i--;
		}
		array[i + 1] = element;
	}
}

template<typename T>
vector<T> Sorter<T>::get()
{
	return array;
}


template<typename T>
void Sorter<T>::set(vector<T> new_array)
{
	array = new_array;
}


template<typename T>
void Sorter<T>::print()
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


template<typename T>
bool Sorter<T>::verify()
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