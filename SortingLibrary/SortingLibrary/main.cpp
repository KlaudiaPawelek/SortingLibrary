// C++ program for sorting values

#include <iostream>
#include <istream> 
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdio.h> 
#include <math.h> 

using namespace std;

void PrintResult()
{
	
}
/* Function to sort an array using insertion sort*/
void insertionSort(vector<int> *V, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = (*V)[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		   greater than key, to one position ahead
		   of their current position */
		while (j >= 0 && (*V)[j] > key)
		{
			(*V)[j + 1] = (*V)[j];
			j = j - 1;
		}
		(*V)[j + 1] = key;
	}
}
void InsertSizeOfArray(int *sizeOfArray)
{
	int tmpSize = 0;
	cout << "Insert size of the input sequence: ";
	cin >> tmpSize;
	*sizeOfArray = tmpSize;
}


void FillArray(vector<int> *sortingArray, int *sizeOfArray)
{
	int value;
	/* initialize random seed: */
	srand(time(NULL));


	for (int n = 0; n < *sizeOfArray; n++)
	{
		/* generate secret number between 1 and 10: */
		value = rand() % 100 + 1;
		(*sortingArray)[n] = value;
	}
}

void QuickSort(vector<int> *sortingArray,int firstElement, int lastElement)
{


}


int main()
{
	//Create Array
	int sizeOfArray = 0;
	InsertSizeOfArray(&sizeOfArray);
	vector<int> sortingArray(sizeOfArray);

	//FillArray
	FillArray(&sortingArray, &sizeOfArray);

	//Quick Sort
	//int firstElement = sortingArray.begin;
	//int lastElement = sortingArray.end;
	//QuickSort(sortingArray, firstElement, lastElement);

	cout << endl;
	return 0;
}