#include "tree.cpp"
struct AVLNode;
class AVLTree : public Tree
{
  public:
	AVLTree() : Tree(){};
	virtual void insert(int key) override;
	virtual void insert(Node* node) override;
	virtual Node* remove(Node* node);
    virtual void remove(int key);
	void fixRoot();
};

struct AVLNode : Node
{
	enum Rotate
	{
		none = 0,
		RR,
		RL,
		LL,
		LR
	};
	AVLNode* left;
	AVLNode* right;
	AVLNode* parent;
	short bf;
	int height;
	AVLNode(int data) : Node(data)
	{
		left = right = parent = 0;
		bf = 0;
		height = 0;
	}
	void balance();
	void updateFactor();
	void rotate(Rotate type);
	Rotate detectRotate();

	void RotRR();
	void RotLR();
	void RotRL();
	void RotLL();

	virtual Node* getParent() override { return parent; };
	virtual Node* getLeft() override { return left; };
	virtual Node* getRight() override { return right; };

	virtual void setParent(Node* node) override { parent = (AVLNode*)node; };
	virtual void setLeft(Node* node) override { left = (AVLNode*)node; };
	virtual void setRight(Node* node) override { right = (AVLNode*)node; };

	virtual void insert(Node* node) override;
	virtual void insert(int key) override;

	virtual Node* get(int key) override;
	virtual int getdata() { return data; }
	virtual void remove(Node* node) override{};
	virtual void remove(int key) override{};
	virtual Node* successor() override;
	virtual Node* predecessor() override;
	virtual Node* leftmost() override;
	virtual Node* rightmost() override;
	virtual int childCount() override;

public:
	virtual void replaceChild(Node* child, Node* newChild);
	virtual Node* getChild()
	{
		if (left)
		{
			return left;
		}
		return right;
	};

	AVLNode** getSelfPointer();
};