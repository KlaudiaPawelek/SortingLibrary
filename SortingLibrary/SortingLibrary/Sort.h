#include <vector>
#include <iostream>
#include <cstdlib> // for the functions rand, srand
#include <ctime> // for the function time
using namespace std;

#pragma once
//FEEL FREE to ADD OTHERS METHODS and OBJECTS!
class Sort
{
private:
	vector<int> vectorOfUnsortedValues; //unsorted
	vector<int> vectorOfSortedValues;	//sorted
	int sizeOfVector;					//size of vector

public:
	
	Sort(); // default constructor, empty vector
	explicit Sort(int sizeOfVector); //additional constructor, fill vector by random numbers
	void PrintVector(); //method can be used to print sorted and unsorted vector
	void sortAlgorithm1(); // method for sorting algorithm from first group: insertion sort or bubble sort;
	void sortAlgorithm2(); // method for sorting algorithm from first group: merge sort/quicksort/radix list sort/heapsort
		
	~Sort();
};

