#include <vector>
#include <cstdlib> // for the functions rand, srand
#include <ctime> // for the function time
#include "Sort.h"


// default constructor, empty vector
Sort::Sort()
{
	vector<int>();
}

//additional constructor, fill vector by random numbers
Sort::Sort(int sizeOfVector)
{
	// set the size
	this->vectorOfSortedValues=vector<int>(sizeOfVector);

	//random numbers
	srand(time(NULL));
	for (int i = 1; i <= sizeOfVector; i++)
	{
		int rnum = rand() % 100 + 1; //the range 1 to 100
		this->vectorOfSortedValues[sizeOfVector - i] = rnum;
	}

}

//method can be used to print sorted and unsorted vector
void Sort::PrintVector()
{
	//todo
}

// method for sorting algorithm from first group: insertion sort or bubble sort;
void Sort::sortAlgorithm1()
{
	//todo
}

// method for sorting algorithm from first group: merge sort/quicksort/radix list sort/heapsort
void Sort::sortAlgorithm2()
{
	//todo
	//try to do something!!!!
}


Sort::~Sort()
{
	//todo
}
