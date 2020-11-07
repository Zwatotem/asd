#pragma once
#include <vector>
#include <iostream>
using std::vector;
template <typename T>
class Sorter
{
private:
	vector<T> array;
	vector<T> old_array;
public:
	Sorter(vector<T> array);
	void sort();
	bool verify();
	vector<T> get();
	void set(vector<T> new_array);
	void print();
};

