#pragma once
#include "Huffman.h"
#include "BinaryTree.h"
#include "SymbolFrequency.h"
#include "Huffman.h"
#include<string>
#include<fstream>
#include<math.h>
#include<bitset>
#include<exception>

using namespace std;

class ExpendDriver
{
public:
	ExpendDriver();
	ExpendDriver(string filename);
	~ExpendDriver();

	void setFileName(string filename);

private:
	string fileName;
	unsigned short symbolFreq[256];
	Huffman huff;
	BinaryTree encodedTree;
	int encoding[256][2];
	void expendFile();
	void getHuffmanEncoding();
};

