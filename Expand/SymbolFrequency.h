#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class SymbolFrequency
{
public:
	SymbolFrequency();
	~SymbolFrequency();
	SymbolFrequency(string fileName);
	void setFileNme(string filename);

	void getSymbolFrequency(unsigned short symbolFrequency1[256]) const;

private:
	string fileName;
	unsigned short symbolFrequency[256];

};

