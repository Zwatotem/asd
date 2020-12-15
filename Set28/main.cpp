#include <iostream>
struct Set
{
	bool *elements;
	int *stack;
	int count;
	Set(int n)
	{
		elements = new bool[n];
		stack = new int[n];
		count = 0;
		for (auto &&i : elements)
		{
			i = false;
		}

		for (auto &&i : stack)
		{
			i = 0;
		}
	}
	~Set()
	{
		delete[] elements;
		delete[] stack;
	}
	void insert(int i)
	{
		elements[i] = true;
		stack[++count] = i;
	}
	bool search(int i)
	{
		return elements[i];
	}
	void select()
	{
		if (!count)
			return;
		elements[stack[count--]] = false;
	}
};
int main()
{
	using namespace std;
	Set a(5);
	a.insert(2);
	a.insert(3);
	cout << a.search(3) << endl;
	a.select();
	cout << a.search(3) << endl;
}