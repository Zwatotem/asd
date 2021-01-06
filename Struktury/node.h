struct Node
{
	int data;

public:
	bool isRoot() { return getParent() == nullptr; }
	Node(int data)
	{
		this->data = data;
	}
	virtual Node *getParent() = 0;
	virtual Node *getLeft() = 0;
	virtual Node *getRight() = 0;

	virtual void setParent(Node *node) = 0;
	virtual void setLeft(Node *node) = 0;
	virtual void setRight(Node *node) = 0;

	virtual void insert(Node *node) = 0;
	virtual void insert(int key) = 0;
	virtual Node *get(int key) = 0;
	virtual int getdata() { return data; }
	virtual void remove(Node *node) = 0;
	virtual void remove(int key) = 0;
	virtual Node *successor() = 0;
	virtual Node *predecessor() = 0;
	virtual Node *leftmost() = 0;
	virtual Node *rightmost() = 0;
	virtual int childCount() = 0;
};