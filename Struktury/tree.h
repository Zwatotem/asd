#pragma once
#include "node.h"
class Tree
{
  public:
    friend class TNode;

  protected:
    Node* root;

  public:
    Tree()
    {
        root = nullptr;
    };
    virtual bool isEmpty()
    {
        return root == nullptr;
    };
    virtual bool isRoot(Node* node)
    {
        return root == node;
    };
    virtual void insert(Node* node);
    virtual void insert(int key);
    virtual Node* get(int key);
    virtual Node* remove(Node* node);
    virtual void remove(int key);
};

struct TNode : public Node
{
    friend class Tree;

    TNode* parent;
    TNode* left;
    TNode* right;

  public:
    TNode(int data) : Node(data)
    {

        this->data = data;
        left = right = parent = nullptr;
    }

    virtual Node* getParent() override
    {
        return parent;
    };
    virtual Node* getLeft() override
    {
        return left;
    };
    virtual Node* getRight() override
    {
        return right;
    };

    virtual void setParent(Node* node) override
    {
        parent = (TNode*)node;
    };
    virtual void setLeft(Node* node) override
    {
        left = (TNode*)node;
    };
    virtual void setRight(Node* node) override
    {
        right = (TNode*)node;
    };

    virtual void insert(Node* node) override;
    virtual void insert(int key) override;
    virtual Node* get(int key) override;
    virtual void remove(Node* node) override{};
    virtual void remove(int key) override{};
    virtual Node* successor() override;
    virtual Node* predecessor() override;
    virtual Node* leftmost() override;
    virtual Node* rightmost() override;
    virtual int childCount() override;

  protected:
    virtual void replaceChild(Node* child, Node* newChild);
    virtual Node* getChild()
    {
        if (left)
        {
            return left;
        }
        return right;
    };
};
