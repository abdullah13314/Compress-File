#pragma once
#include "Heap.h"
#include "BinaryTree.h"
class Huffman
{
public:
	Huffman();
	~Huffman();

	void AddTrees(unsigned short symbolFrequency[256]);
	void HuffmanTree(BinaryTree &tree) ;
	void HuffmanEncodingKey(int encoding[256][2]);

private:
	Heap priorityQueue;
	void huffmanAlgo();
	void recEcoding(BinaryTree tree, int code, int encoding[256][2], int countBits);

};

