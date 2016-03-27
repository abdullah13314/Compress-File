// Compress.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SymbolFrequency.h"
#include "BinaryTree.h"
#include "Heap.h"
#include "Huffman.h"
#include "CompressClass.h"
#include "ExpendDriver.h"
#include <iostream>
#include <string>
#include <fstream>
#include<bitset>
#include <algorithm>

/*
static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;
*/

using namespace std;

//void PrintEcoding(BinaryTree tree, int code);

int main(int argc, char *argv[])
{
	string file_original;
	file_original.append(argv[1]);
	/*
	string file_original, file_compresed, file_expended;
	file_original.append(argv[1]);
	file_compresed.append(file_original);
	file_compresed.append(".huf");
	file_expended.append(file_compresed);
	file_expended.append(".puf");
	
	ofstream myfile(file_original);

	if (myfile.is_open())
	{
		for (int i = 0; i < 1000000; i++)
		{
			myfile << alphanum[rand() % stringLength];
		}
	}

	myfile.close();
	
	*/

	


	CompressClass c(file_original);
	//c.setFileName(file_original);
	//ExpendDriver e(file_compresed);

	/*
	char ch,ch1;
	fstream fin(file_original, fstream::in);
	fstream fin1(file_expended, fstream::in);
	while (fin >> noskipws >> ch) {
		fin1 >> noskipws >> ch1;
		if (ch != ch1)
		{
			cout <<endl << "Characters in the file are not the same. " << endl;
			break;
		}
	}
	cout << "Characters in the file are the same. " << endl;
	*/
	//cout << "." << (int)'.' << endl;
	/*
	char buff;
	buff = buff & 0;
	buff = (buff << 7) ;
	
	for (int i = 0; i < 8; i++)
	{
		buff = (buff >> 1) ;
		cout << bitset<8>(buff) << endl;
	}
	*/
	/*
	SymbolFrequency test("test.txt");
	unsigned short t1[256];
	test.getSymbolFrequency(t1);
	Huffman huff;
	huff.AddTrees(t1);
	int encoding[256][2];
	huff.HuffmanEncodingKey(encoding);
	for (int i = 0; i < 256; i++)
	{
		if (encoding[i][0] != -1)
		{
			cout << " Char: " << (char)i << " Code: " << encoding[i][0] << " Bits: " << encoding[i][1] << endl;
		}
	}
	*/
	//cout << t1[0];
	/*
	Heap h1;
	h1.Add(t1);
	//cout << h1.getCount();
	while (h1.getCount() != 1)
	{
		BinaryTree tr1, tr2;
		h1.Remove(tr1);
		h1.Remove(tr2);
		cout << tr1.getRootCharFreq() << endl;
		cout << tr1.getRootCharInt() << endl;
		cout << tr2.getRootCharFreq() << endl;
		cout << tr2.getRootCharInt() << endl << endl;

		tr1 += tr2;
		h1.Add(tr1);
	}

	BinaryTree tree1, tree;
	h1.Top(tree1);
	tree = tree1;
	int code;
	if (tree1.MoveToLeftChild())
	{
		code = 0;
		PrintEcoding(tree1, code);
	}
	if (tree.MoveToRightChild())
	{
		code = 1;
		PrintEcoding(tree, code);
	}
	*/
	/*
	while (true) {
		BinaryTree b1(12, 4);
		BinaryTree b2(4, 3);
		cout << b1.getRootCharFreq() << endl;
		b1 += b2;
		b2 = b1;
		cout << b1.getRootCharFreq() << endl;
		b1.MoveToLeftChild();
		cout << b1.getRootCharFreq() << endl;
		cout << b1.getRootCharInt() << endl;
		b2.MoveToRightChild();
		cout << b2.getRootCharFreq() << endl;
		cout << b2.getRootCharInt() << endl;
	}
	*/
    return 0;
}
/*
void PrintEcoding(BinaryTree tree, int code)
{
	//cout << "Node char: " << tree.getRootCharInt() << "Frequency " << tree.getRootCharFreq() << endl;
	if (tree.getRootCharInt() != -1)
	{
		cout << "Char : " << (char)tree.getRootCharInt() << " Code: " << code << endl;
	}
	else
	{
		BinaryTree tree1 = tree;
		if (tree1.MoveToLeftChild())
		{
			if (code == 0)
			{
				code = 1;
			}
			code = code * 10;
			PrintEcoding(tree1, code);
			code = code / 10;
		}
		if (tree.MoveToRightChild())
		{
			if (code == 0)
			{
				code = 1;
			}
			code = code * 10 + 1;
			PrintEcoding(tree, code);
		}
	}
}
*/