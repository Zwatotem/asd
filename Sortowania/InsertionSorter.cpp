#include "InsertionSorter.h"

using std::vector;

template <typename T>
InsertionSorter<T>::InsertionSorter(vector<T> array) :
  Sorter<T>(array)
{
}

template <typename T>
void InsertionSorter<T>::sort()
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
