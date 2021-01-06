#pragma once
#include "tree.cpp"

class BSTree : public Tree
{
public:
	BSTree() : Tree() {}
	virtual void insert(int) override;
	virtual void insert(Node*) override;
	virtual Node *remove(Node *) override;
	virtual void remove(int) override;
};

struct BSNode : public Node
{
	BSNode *left;
	BSNode *right;
	BSNode *parent;

	BSNode(int key) : Node(key){
		left=right=parent=nullptr;
	};

	virtual Node *getParent() override { return parent; };
	virtual Node *getLeft() override { return left; };
	virtual Node *getRight() override { return right; };

	virtual void setParent(Node *node) override { parent = (BSNode *)node; };
	virtual void setLeft(Node *node) override { left = (BSNode *)node; };
	virtual void setRight(Node *node) override { right = (BSNode *)node; };

	virtual void insert(Node *node) override;
	virtual void insert(int key) override;
	virtual Node *get(int key) override;
	virtual void remove(Node *node) override{};
	virtual void remove(int key) override{};
	virtual Node *successor() override;
	virtual Node *predecessor() override;
	virtual Node *leftmost() override;
	virtual Node *rightmost() override;
	virtual int childCount() override;

	void replaceChild(Node *, Node *);
	Node *getChild() { return left ? left : right; };
};