// C++ program for sorting values

#include <iostream>
#include <istream> 
#include <vector>
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

void QuickSort()
{


}


int main()
{
	int sizeOfArray = 0;
	InsertSizeOfArray(&sizeOfArray);

	vector<int> sortingArray(sizeOfArray);
	

	cout << endl;
	return 0;
}