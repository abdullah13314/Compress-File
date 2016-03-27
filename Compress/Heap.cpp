#include "stdafx.h"
#include "Heap.h"


Heap::Heap()
{
	BinaryTree b1(-1,-1);
	data.push_back(b1);
}


Heap::~Heap()
{
}

bool Heap::Add(unsigned short symbolFrequency[256])
{
	for (int i = 0; i < 256; i++)
	{
		if (symbolFrequency[i] != 0)
		{
			Add(symbolFrequency[i], i);
			//cout << "checck4" << endl;
		}
	}
	return true;
}

bool Heap::Add(int charFreq, int charc)
{
	//cout << charFreq << endl;
	BinaryTree b1(charFreq, charc);
	//cout << "checck1"<< endl;
	//cout << b1.getRootCharFreq() << endl;
	data.push_back(b1);
	//cout << b1.getRootCharFreq();
	//cout << "checck2" << endl;
	count++;
	int position = count;
	while ((data[position].getRootCharFreq() < data[position / 2].getRootCharFreq())&&(position > 0))
	{
		BinaryTree temp;
		temp = data[position];
		data[position] = data[position/2];
		data[position / 2] = temp;
		position = position / 2;

	}
	b1.Clear();
	//cout << "checck3" << endl;

	return true;
}

bool Heap::Add(BinaryTree &sTree)
{
	data.push_back(sTree);
	count++;
	int position = count;
	while ((data[position].getRootCharFreq() < data[position / 2].getRootCharFreq()) && (position > 0))
	{
		BinaryTree temp;
		temp = data[position];
		data[position] = data[position / 2];
		data[position / 2] = temp;
		position = position / 2;
	}
	return true;
}

bool Heap::Remove(BinaryTree &sTree)
{
	if (count == 0)
	{
		return false;
	}
	else
	{
		sTree = data[1];
		data[1] = data[count];
		data.pop_back();
		count--;
		percolateDown(1);
		return true;
	}
}

bool Heap::Top(BinaryTree &sTree)
{
	if (count == 0)
	{
		return false;
	}
	else
	{
		sTree = data[1];
		return true;
	}
}


void Heap::percolateDown(int position)
{
	int child = position * 2;
	if (child > count)
	{
		return;
	}
	if ((child != count) && (data[child + 1].getRootCharFreq() < data[child].getRootCharFreq()))
	{
		child++;
	}
	if (data[position].getRootCharFreq() > data[child].getRootCharFreq())
	{
		BinaryTree temp;
		temp = data[position];
		data[position] = data[child];
		data[child] = temp;
		percolateDown(child);
	}
}

int Heap::getCount() const
{
	return count;
}
