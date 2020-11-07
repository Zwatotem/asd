#pragma once
#include <vector>
#include <iostream>

using std::vector;
template <typename T>
class Sorter
{
public:
	vector<T> array;
	vector<T> old_array;

public:
	Sorter() = default;
	Sorter(vector<T> array) : array(array){};
	Sorter(const Sorter<T> &) = default;
	virtual void sort() {old_array = array;};
	virtual bool verify()
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
	};
	virtual vector<T> get()
	{
		return array;
	};
	virtual void set(vector<T> new_array)
	{
		array = new_array;
	};
	virtual void print()
	{
		using std::cout;
		using std::endl;
		cout << "(";
		for (auto i : array)
		{
			cout << i << ", ";
		}
		cout << "\b\b)" << endl;
	};
};
