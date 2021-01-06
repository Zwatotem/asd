#pragma once
#include "bst.h"

#include "tree.h"
void BSTree::insert(Node *node)
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

void BSNode::insert(Node *node)
{
	if (node->data < data)
	{
		if (left == nullptr)
		{
			left = (BSNode*)node;
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
			right = (BSNode*)node;
			node->setParent(this);
		}
		else
		{
			right->insert(node);
		}
	}
}

void BSTree::insert(int key)
{
	Node *node = new BSNode(key);
	insert(node);
}

void BSNode::insert(int key)
{
	Node *node = new BSNode(key);
	insert(node);
}

void BSNode::replaceChild(Node *child, Node *newChild)
{
	if (left == child)
	{
		left = (BSNode*)newChild;
	}
	else
	{
		right = (BSNode*)newChild;
	}
}

void BSTree::remove(int key)
{
	Node *toremove = get(key);
	if (toremove != nullptr)
	{
		toremove = remove(toremove);
		delete toremove;
	}
}

Node *BSTree::remove(Node *bnode)
{
	BSNode* node = static_cast<BSNode*>(bnode);
	switch (node->childCount())
	{
	case 0:
		if (isRoot(node))
		{
			return node;
		}
		else
		{
			((BSNode*)(node->getParent()))->replaceChild(node, nullptr);
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
			Node *child = node->BSNode::getChild();
			node->parent->BSNode::replaceChild(node, child);
			child->setParent(node->parent);
			return node;
		}
	case 2:
		Node *replacement = node->successor();
		if (replacement != nullptr)
			replacement = node->predecessor();
		replacement = remove(replacement);
		replacement->setParent(node->parent);
		replacement->setLeft(node->left);
		replacement->setRight(node->right);
		if (replacement->getParent() != nullptr)
			((BSNode*)replacement->getParent())->replaceChild(node, replacement);
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

Node *BSNode::get(int key)
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


Node *BSNode::successor()
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

Node *BSNode::predecessor()
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

Node *BSNode::leftmost()
{
	return left != nullptr ? left->leftmost() : this;
}

Node *BSNode::rightmost()
{
	return right != nullptr ? right->rightmost() : this;
}
int BSNode::childCount()
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