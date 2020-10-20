#pragma once
#include <vector>
#include <iostream>
using std::vector;
template <typename T>
class MergeSorter
{
private:
	vector<T> array;
	vector<T> old_array;
	void merge_sort(int start, int end);
	void merge(int start, int mid, int end);
public:
	MergeSorter(vector<T> array);
	void sort();

	bool verify();
	vector<T> get();
	void set(vector<T> new_array);
	void print();
};

