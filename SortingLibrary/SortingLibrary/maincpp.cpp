#include <iostream>
#include <istream>
#include <vector>
#include "Sort.h"
using namespace std;

int main()
{
	//ask user
	int sizeOfVector = 0;
	cout << "Insert size of vector, which will be contained random values: ";
	cin >> sizeOfVector;

	Sort s(sizeOfVector);


	cout << endl;
	return 0;
}