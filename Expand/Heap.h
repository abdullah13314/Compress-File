#pragma once
#include <vector>
#include "BinaryTree.h"
#include <iostream>

using namespace std;
class Heap
{
public:
	
	Heap();
	//Heap(const Heap &source);
	~Heap();

	bool Add(unsigned short symbolFrequency[256]);
	bool Add(int charFreq, int charc);
	bool Add(BinaryTree &sTree);

	//bool Contains(int charc);
	//bool Retrive(int& charFreq, int& charc);
	bool Remove(BinaryTree &sTree);
	bool Top(BinaryTree &sTree);
	//bool Clear();
	
	int getCount() const;

	//Heap& operator=(const Heap &copy);


private:
	vector<BinaryTree> data;
	int count;
	void percolateDown(int position);

};

