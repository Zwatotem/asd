#include <iostream>
// #include "tree.cpp"
// #include "bst.cpp"
#include "avl.cpp"

int main()
{
	AVLTree tree;
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.remove(2);
	std::cout << tree.get(1)->getdata() << std::endl;
	return 0;
}