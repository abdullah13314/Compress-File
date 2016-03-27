#include "stdafx.h"
#include "SymbolFrequency.h"


SymbolFrequency::SymbolFrequency()
{
	for (int i = 0; i < 256; i++)
	{
		symbolFrequency[i] = 0;
	}
}


SymbolFrequency::~SymbolFrequency()
{
}

SymbolFrequency::SymbolFrequency(string fileName)
{
	for (int i = 0; i < 256; i++)
	{
		symbolFrequency[i] = 0;
	}
	char ch;
	fstream fin(fileName.c_str(), fstream::in);
	while (fin >> noskipws >> ch) {
		symbolFrequency[(int)ch]++;
	}
}

void SymbolFrequency::setFileNme(string filename)
{
	char ch;
	fstream fin(fileName.c_str(), fstream::in);
	while (fin >> noskipws >> ch) {
		symbolFrequency[(int)ch]++;
	}
}

void SymbolFrequency::getSymbolFrequency(unsigned short symbolFrequency1[256]) const
{
	for (int i = 0; i < 256; i++)
	{
		symbolFrequency1[i] = symbolFrequency[i];
	}
}