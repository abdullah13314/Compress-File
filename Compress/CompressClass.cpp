#include "stdafx.h"
#include "CompressClass.h"


CompressClass::CompressClass()
{
}


CompressClass::CompressClass(string filename)
{
	fileName.append(filename);
	getSymbolFrequency();
	getHuffmanEncoding();
	createCompressedFile();
}


CompressClass::~CompressClass()
{
}

void CompressClass::setFileName(string filename)
{
	fileName = filename;
	getSymbolFrequency();
	getHuffmanEncoding();
	createCompressedFile();
}

void CompressClass::getSymbolFrequency()
{
	SymbolFrequency symb(fileName);
	symb.getSymbolFrequency(symbolFreq);
}

void CompressClass::getHuffmanEncoding()
{
	Huffman huff;
	huff.AddTrees(symbolFreq);
	huff.HuffmanEncodingKey(encoding);
}

void CompressClass::createCompressedFile()
{
	string f;
	f.append(fileName);
	f.append(".huf");
	ofstream myfile(f.c_str(), ios::binary);
	int totalCount = 0;
	if (myfile.is_open())
	{
		myfile << "This is the compressed file.\n";
		for (int i = 0; i < 256; i++)
		{
			totalCount += symbolFreq[i];
			myfile << symbolFreq[i] << endl;
		}
		myfile << totalCount << endl;
		unsigned char ch, buff;
		buff = buff & 0;
		int code, numCodeBits, bit;
		int numBuffBits = 0;
		//fstream fin(fileName, ios::in |ios::binary);
		fstream fin(fileName.c_str(), fstream::in);
		while (fin >> noskipws >> ch) {
			code = encoding[(int)ch][0];
			numCodeBits = encoding[(int)ch][1];
			while (numCodeBits != 0)
			{
				bit = (code & (int)pow(2, (numCodeBits-1)));
				if (bit != 0)
				{
					buff = (buff << 1) | 1;
					numBuffBits++;
					numCodeBits--;
				}
				else
				{
					buff = (buff << 1);
					numBuffBits++;
					numCodeBits--;
				}
				if (numBuffBits == 8)
				{
					myfile << buff;
					//myfile << (int)buff;
					//myfile << bitset<8>(buff);
					numBuffBits = 0;
				}
			}

		}
		
		if (numBuffBits != 0)
		{
			buff = buff << (8 - numBuffBits);
			myfile << buff;
			//myfile << bitset<8>(buff);
			numBuffBits = 0;
		}
		myfile.close();
	}
}