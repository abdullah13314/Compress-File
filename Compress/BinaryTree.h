#pragma once
#include<iostream>

using namespace std;
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(int charFreq, int charc);
	BinaryTree(const BinaryTree &source);
	~BinaryTree();

	bool MoveToLeftChild();
	bool MoveToRightChild();
	int getRootCharInt() const;
	int getRootCharFreq() const;

	BinaryTree& operator=(const BinaryTree &copy);
	//BinaryTree operator+(const BinaryTree &copy);
	BinaryTree& operator+=(const BinaryTree &copy);
	void Clear();

private:
	struct Node
	{
		int characterFrequency = 0;
		int character = -1;
		Node* left = NULL;
		Node* right = NULL;
	};
	Node *root;
	void clear(Node *&pNode);
	void copy(Node *&nNode, Node* copy);

};

