#include "avl.h"
void AVLTree::insert(int key)
{
	AVLNode* node = new AVLNode(key);
	insert(node);
}
void AVLTree::insert(Node* node)
{
	if (isEmpty())
	{
		root = node;
	}
	else
	{
		root->insert(node);
	}
	fixRoot();
}

void AVLTree::remove(int key)
{
	Node* toremove = get(key);
	if (toremove != nullptr)
	{
		toremove = remove(toremove);
		delete toremove;
	}
}
Node* AVLTree::remove(Node* bnode)
{
	AVLNode* node = static_cast<AVLNode*>(bnode);
	AVLNode* parentNode;
	switch (node->childCount())
	{
	case 0:
		if (isRoot(node))
		{
			return node;
		}
		else
		{
			parentNode = (AVLNode*)node->getParent();
			((AVLNode*)(node->getParent()))->replaceChild(node, nullptr);
			fixRoot();
			return node;
		}
	case 1:
		if (isRoot(node))
		{
			root = node->getChild();
			root->setParent(nullptr);
			fixRoot();
			return node;
		}
		else
		{
			parentNode = (AVLNode*)node->getParent();
			Node* child = node->AVLNode::getChild();
			node->parent->AVLNode::replaceChild(node, child);
			child->setParent(node->parent);
			fixRoot();
			return node;
		}
	case 2:
		Node* replacement = node->successor();
		if (replacement != nullptr)
			replacement = node->predecessor();
		parentNode = (AVLNode*)replacement->getParent();
		replacement = remove(replacement);
		replacement->setParent(node->parent);
		replacement->setLeft(node->left);
		replacement->setRight(node->right);
		if (replacement->getParent() != nullptr)
			((AVLNode*)replacement->getParent())->replaceChild(node, replacement);
		if (replacement->getLeft() != nullptr)
			replacement->getLeft()->setParent(replacement);
		if (replacement->getRight() != nullptr)
			replacement->getRight()->setParent(replacement);
		node->left = node->right = node->parent = nullptr;
		if (isRoot(node))
			root = replacement;
		parentNode->balance();
		fixRoot();
		return node;
		// default:
	}
	return nullptr;
}
void AVLTree::fixRoot()
{
	while (root->getParent() != nullptr)
	{
		root = root->getParent();
	}
}
void AVLNode::insert(Node* node)
{
	if (node->data < data)
	{
		if (left == nullptr)
		{
			left = (AVLNode*)node;
			node->setParent(this);
			((AVLNode*)node)->balance();
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
			right = (AVLNode*)node;
			node->setParent(this);
			((AVLNode*)node)->balance();
		}
		else
		{
			right->insert(node);
		}
	}
}

void AVLNode::balance()
{
	updateFactor();
	switch (bf)
	{
	case -2:
	case +2:
		rotate(detectRotate());
	default:
		if (parent)
		{
			parent->balance();
		}
		break;
	}
}

void AVLNode::updateFactor()
{
	height = std::max(left ? left->height : 0, right ? right->height : 0) + 1;
	bf = ((left ? left->height : 0) - (right ? right->height : 0));
}

AVLNode::Rotate AVLNode::detectRotate()
{
	if (bf == 2 && left->bf == 1)
	{
		return RR;
	}
	if (bf == 2 && left->bf == -1)
	{
		return LR;
	}
	if (bf == -2 && right->bf == -1)
	{
		return LL;
	}
	if (bf == -2 && right->bf == 1)
	{
		return RL;
	}
	return none;
}

void AVLNode::rotate(Rotate type)
{
	switch (type)
	{
	case RR:
		return RotRR();
	case RL:
		return RotRL();
	case LR:
		return RotLR();
	case LL:
		return RotLL();
	default:
		break;
	}
}

void AVLNode::RotRR()
{
	AVLNode** selfPointer = getSelfPointer();
	AVLNode* transfer = left->right;
	left->setRight(this);
	left->setParent(parent);
	parent = left;
	left = transfer;
	if (transfer)
		transfer->setParent(this);
	if (selfPointer)
	{
		*selfPointer = left;
	}
}

void AVLNode::RotLL()
{
	AVLNode** selfPointer = getSelfPointer();
	AVLNode* transfer = right->left;
	right->setLeft(this);
	right->setParent(parent);
	parent = right;
	right = transfer;
	if (transfer)
		transfer->setParent(this);
	if (selfPointer)
	{
		*selfPointer = right;
	}
}

void AVLNode::RotLR()
{
	left->RotLL();
	RotRR();
}

void AVLNode::RotRL()
{
	right->RotRR();
	RotLL();
}

void AVLNode::insert(int key)
{
	Node* node = new AVLNode(key);
	insert(node);
}

Node* AVLNode::get(int key)
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

Node* AVLNode::successor()
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

Node* AVLNode::predecessor()
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

Node* AVLNode::leftmost() { return left != nullptr ? left->leftmost() : this; }

Node* AVLNode::rightmost() { return right != nullptr ? right->rightmost() : this; }
int AVLNode::childCount()
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

AVLNode** AVLNode::getSelfPointer()
{
	if (parent)
	{
		if (this == parent->right)
		{
			return &(parent->right);
		}
		else
		{
			return &(parent->left);
		}
	}
	else
	{
		return nullptr;
	}
}

void AVLNode::replaceChild(Node* child, Node* newChild)
{
	if (left == child)
	{
		left = (AVLNode*)newChild;
	}
	else
	{
		right = (AVLNode*)newChild;
	}
}