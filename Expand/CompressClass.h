#pragma once
#include "Huffman.h"
#include "SymbolFrequency.h"
#include<string>
#include<fstream>
#include<math.h>
#include<bitset>

using namespace std;

class CompressClass
{
public:
	CompressClass();
	CompressClass(string filename);
	void setFileName(string filename);
	~CompressClass();

private:
	string fileName;
	unsigned short symbolFreq[256];
	int encoding[256][2];
	void getSymbolFrequency();
	void getHuffmanEncoding();
	void createCompressedFile();
};

