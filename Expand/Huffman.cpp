#include "stdafx.h"
#include "Huffman.h"


Huffman::Huffman()
{
}


Huffman::~Huffman()
{
}

void Huffman::AddTrees(unsigned short symbolFrequency[256])
{
	priorityQueue.Add(symbolFrequency);
	huffmanAlgo();
}

void Huffman::HuffmanTree(BinaryTree &tree) 
{
	priorityQueue.Top(tree);
}

// 1 added at the starting of each code to use integer for holding the encoding
void Huffman::HuffmanEncodingKey(int encoding[256][2]) 
{
	for (int i = 0; i < 256; i++)
	{
		encoding[i][0] = -1;
	}
	BinaryTree tree1, tree;
	priorityQueue.Top(tree1);
	tree = tree1;
	int code;
	code = code & 0;
	int countBits = 0;
	if (tree1.MoveToLeftChild())
	{
		countBits++;
		recEcoding(tree1, code,encoding, countBits);
		countBits--;

	}
	if (tree.MoveToRightChild())
	{
		countBits++;
		code = code|1;
		recEcoding(tree, code, encoding, countBits);
	}
}
void Huffman::huffmanAlgo()
{
	while (priorityQueue.getCount() != 1)
	{
		BinaryTree tr1, tr2;
		priorityQueue.Remove(tr1);
		priorityQueue.Remove(tr2);
		tr1 += tr2;
		priorityQueue.Add(tr1);
	}
}

void Huffman::recEcoding(BinaryTree tree, int code, int encoding[256][2], int countBits)
{
	//cout << "Node char: " << tree.getRootCharInt() << "Frequency " << tree.getRootCharFreq() << endl;
	if (tree.getRootCharInt() != -1)
	{
		encoding[tree.getRootCharInt()][0] = code;
		encoding[tree.getRootCharInt()][1] = countBits;
		//cout << "Char : " << (char)tree.getRootCharInt() << " Code: " << code << endl;
	}
	else
	{
		BinaryTree tree1 = tree;
		if (tree1.MoveToLeftChild())
		{
		
			countBits++;
			code = code << 1;
			recEcoding(tree1, code, encoding, countBits);
			code = code >> 1;
			countBits--;
		}
		if (tree.MoveToRightChild())
		{
			
			countBits++;
			code = code << 1;
			code = code | 1;
			recEcoding(tree, code, encoding, countBits);
		}
	}
}