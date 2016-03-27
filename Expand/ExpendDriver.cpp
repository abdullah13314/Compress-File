#include "stdafx.h"
#include "ExpendDriver.h"


ExpendDriver::ExpendDriver()
{
}

ExpendDriver::ExpendDriver(string filename)
{
	fileName = filename;
	expendFile();
}

ExpendDriver::~ExpendDriver()
{
}

void ExpendDriver::setFileName(string filename)
{
	fileName = filename;
	expendFile();
}

void ExpendDriver::expendFile()
{
	string s;
	int charCount;
	fstream fin(fileName.c_str(), ios::in | ios::binary);
	//	fstream fin(fileName, fstream::in);	

	getline(fin, s);
	cout << s << endl;
	for (int i = 0; i < 256; i++)
	{
		fin >> symbolFreq[i];
		cout << "Char: " << i << " Freq: " << symbolFreq[i] << endl;
	}
	getHuffmanEncoding();

	/*
	for (int i = 0; i < 256; i++)
	{
		if (encoding[i][0] != -1)
		{
			cout << "Encoded: " << (char)i << " " << encoding[i][0] << " Bit size: " << encoding[i][1] << endl;
		}
	}*/
	//getline(fin, s);

	fin >> charCount;
	cout << "Total char count " << charCount << endl;
	unsigned char ch, buff;
	int bitCount = 8;
	//First character is garbage value
	fin >> noskipws >> ch;
	//fin >> noskipws >> ch;

	string f;
	f.append(fileName);
	f.append(".puf");
	ofstream myfile(f.c_str());
	BinaryTree tree1 = encodedTree;
	if (myfile.is_open())
	{
		while (fin>> noskipws >> ch) {
			//cout << (int)ch << endl;
			//cout << bitset<8>(ch) << endl;
			bitCount = 8;
			//buff = buff | 1;
			//buff = buff << 7;
			while ((charCount != 0) && (bitCount != 0))
			{
				buff = (int)pow(2, (bitCount-1));
				//cout << bitset<8>(buff) << endl;
				if (ch&buff)
				{
					//cout << bitCount << endl;
					tree1.MoveToRightChild();
				}
				else
				{
					tree1.MoveToLeftChild();
				}
				if (tree1.getRootCharInt() != -1)
				{
					//cout << (char)tree1.getRootCharInt();
					myfile << (char)tree1.getRootCharInt();
					tree1 = encodedTree;
					charCount--;
				}
				bitCount--;
				//buff = buff >> 1;
			}
		}
	}
	myfile.close();
}

void ExpendDriver::getHuffmanEncoding()
{
	huff.AddTrees(symbolFreq);
	huff.HuffmanTree(this->encodedTree);
	//huff.HuffmanEncodingKey(encoding);
}

