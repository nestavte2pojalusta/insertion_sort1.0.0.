#include "stdafx.h"
#include <iostream>
#include <string>
#include <utility>
#include <sstream>
using namespace std;
void insort(int *array, unsigned int size)
{
	for (unsigned int i = 0; i<size; i++)
	{
		for (unsigned int j = i; j>0; j--)
		{
			if (array[j]<array[j - 1]) { swap(array[j - 1], array[j]); }
			else break;
		}
	}
}
void out(int *array, unsigned int size)
{
	for (unsigned int i = 0; i<size; i++)
	{
		cout << array[i] << " ";
	}
}
bool input(int *array, unsigned int size)
{
	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);
	for (unsigned int i = 0; i<size; i++)
	{
		if (!(stream >> array[i])) {
			cout << "An error has occured while reading input data.";
			return false;
		}
	}
	return true;
}

int main(int argc, char** argv) {
	unsigned int size;
	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);
	if (!(stream >> size)) {
		cout << "An error has occured while reading input data." << endl;
		return -1;
	}
	int *array = new int[size];
	if (input(array, size))
	{
		insort(array, size);
		out(array, size);
	}
	delete[]array;
	return 0;
}
