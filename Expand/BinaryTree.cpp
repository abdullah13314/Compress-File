#include "stdafx.h"
#include "BinaryTree.h"


BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::BinaryTree(const BinaryTree &source)
{
	root = NULL;
	*this = source;
}


BinaryTree::~BinaryTree()
{
	clear(root);
}

BinaryTree::BinaryTree(int charFreq, int charc)
{
	Node* proot = new Node;
	proot->character = charc;
	proot->characterFrequency = charFreq;
	proot->left = NULL;
	proot->right = NULL;
	root = proot;
}

bool BinaryTree::MoveToLeftChild()
{
	if (root->left == NULL)
	{
		return false;
	}
	clear(root->right);
	Node* temp = root;
	root = root->left;
	delete temp;
	return true;
}

bool BinaryTree::MoveToRightChild()
{
	if (root->right == NULL)
	{
		return false;
	}
	clear(root->left);
	Node* temp = root;
	root = root->right;
	delete temp;
	return true;
}

int BinaryTree::getRootCharInt() const
{
	return root->character;
}

int BinaryTree::getRootCharFreq() const
{
	return root->characterFrequency;
}

void BinaryTree::clear(Node *&pNode)
{
	if (pNode != NULL)
	{
		//cout << pNode->characterFrequency;
		clear(pNode->left);
		clear(pNode->right);
		delete pNode;
		pNode = NULL;
	}
}

BinaryTree& BinaryTree::operator+=(const BinaryTree &source)
{
	if (source.root == NULL)
	{
		return *this;
	}
	Node* pNode = new Node;
	pNode->character = -1;
	pNode->characterFrequency = this->root->characterFrequency + source.getRootCharFreq();
	Node* nNode;
	copy(nNode, source.root);
	if (this->root->characterFrequency > source.getRootCharFreq())
	{
		pNode->left = this->root;
		pNode->right = nNode;
	}
	else
	{
		pNode->left = nNode;
		pNode->right = this->root;
	}
	this->root = pNode;
	
	return *this;
}

void BinaryTree::copy(Node *&nNode, Node* sNode)
{
	if (sNode == NULL)
	{
		nNode = NULL;
		return;
	}
	nNode = new Node;
	nNode->character = sNode->character;
	nNode->characterFrequency = sNode->characterFrequency;
	nNode->left = NULL;
	nNode->right = NULL;
	copy(nNode->left, sNode->left);
	copy(nNode->right, sNode->right);
}

BinaryTree& BinaryTree::operator=(const BinaryTree &source)
{
	//cout << "Create copy" << endl;
	if (this == &source)
	{
		return *this;
	}
	clear(root);	
	copy(root, source.root);
	return *this;
}

void BinaryTree::Clear() 
{
	clear(root);
	root = NULL;
}
