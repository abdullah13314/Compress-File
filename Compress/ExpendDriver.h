#pragma once
#include "Huffman.h"
#include "SymbolFrequency.h"
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
	BinaryTree encodedTree;
	int encoding[256][2];
	void expendFile();
	void getHuffmanEncoding();
};

