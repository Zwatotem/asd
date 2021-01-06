#include "tree.h"

void Tree::insert(Node* node)
{
	if (isEmpty())
	{
		root = node;
		node->setParent(nullptr);
	}
	else
	{
		root->insert(node);
	}
}

void TNode::insert(Node* node)
{
	if (node->data < data)
	{
		if (left == nullptr)
		{
			left = (TNode*)node;
			node->setParent(this);
		}
		else
		{
			left->insert(node);
		}
	}
	else
	{
		if (right == nullptr)
		{
			right = (TNode*)node;
			node->setParent(this);
		}
		else
		{
			right->insert(node);
		}
	}
}

void Tree::insert(int key)
{
	Node* node = new TNode(key);
	insert(node);
}

void TNode::insert(int key)
{
	Node* node = new TNode(key);
	insert(node);
}

Node* Tree::get(int key) { return isEmpty() ? nullptr : root->get(key); }

void Tree::remove(int key)
{
	Node* toremove = get(key);
	if (toremove != nullptr)
	{
		toremove = remove(toremove);
		delete toremove;
	}
}

Node* TNode::get(int key)
{
	if (key == data)
	{
		return this;
	}
	if (key < data)
	{
		if (left == nullptr)
		{
			return nullptr;
		}
		else
		{
			return left->get(key);
		}
	}
	else
	{
		if (right == nullptr)
		{
			return nullptr;
		}
		else
		{
			return right->get(key);
		}
	}
}

Node* TNode::successor()
{
	if (right != nullptr)
	{
		return right->leftmost();
	}
	else
	{
		if (parent != nullptr && parent->left == this)
		{
			return parent;
		}
	}
	return nullptr;
}

Node* TNode::predecessor()
{
	if (left != nullptr)
	{
		return left->rightmost();
	}
	else
	{
		if (parent != nullptr && parent->right == this)
		{
			return parent;
		}
	}
	return nullptr;
}

Node* TNode::leftmost() { return left != nullptr ? left->leftmost() : this; }

Node* TNode::rightmost() { return right != nullptr ? right->rightmost() : this; }
int TNode::childCount()
{
	if (left == right && right == nullptr)
	{
		return 0;
	}
	if (left == nullptr || right == nullptr)
	{
		return 1;
	}
	else
		return 2;
}
void TNode::replaceChild(Node* child, Node* newChild)
{
	if (left == child)
	{
		left = (TNode*)newChild;
	}
	else
	{
		right = (TNode*)newChild;
	}
}
Node* Tree::remove(Node* bnode)
{
	TNode* node = static_cast<TNode*>(bnode);
	switch (node->childCount())
	{
	case 0:
		if (isRoot(node))
		{
			return node;
		}
		else
		{
			((TNode*)(node->getParent()))->replaceChild(node, nullptr);
			return node;
		}
	case 1:
		if (isRoot(node))
		{
			root = node->getChild();
			root->setParent(nullptr);
			return node;
		}
		else
		{
			Node* child = node->TNode::getChild();
			node->parent->TNode::replaceChild(node, child);
			child->setParent(node->parent);
			return node;
		}
	case 2:
		Node* replacement = node->successor();
		if (replacement != nullptr)
			replacement = node->predecessor();
		replacement = remove(replacement);
		replacement->setParent(node->parent);
		replacement->setLeft(node->left);
		replacement->setRight(node->right);
		if (replacement->getParent() != nullptr)
			((TNode*)replacement->getParent())->replaceChild(node, replacement);
		if (replacement->getLeft() != nullptr)
			replacement->getLeft()->setParent(replacement);
		if (replacement->getRight() != nullptr)
			replacement->getRight()->setParent(replacement);
		node->left = node->right = node->parent = nullptr;
		if (isRoot(node))
			root = replacement;
		return node;
		// default:
	}
	return nullptr;
}
