#pragma once
#include <vector>
#include <iostream>
#include "Sorter.cpp"
using std::vector;
template <typename T>
class InsertionSorter : public Sorter<T>
{
    using Sorter<T>::array;
    using Sorter<T>::old_array;

public:
    InsertionSorter(vector<T> array);

    virtual void sort() override;
};
