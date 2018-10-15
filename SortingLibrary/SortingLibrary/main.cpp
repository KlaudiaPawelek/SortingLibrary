// C++ program for sorting values

#include <iostream>
#include <istream> 
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdio.h> 
#include <math.h> 

using namespace std;

{
}
{
	int i, key, j;
	{
		key = (*V)[i];
		j = i - 1;

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
	//initialize random seed
	srand(time(NULL));


	for (int n = 0; n < *sizeOfArray; n++)
	{
<<<<<<< HEAD
		//generate secret number between 1 and 100
=======
>>>>>>> master
		value = rand() % 100 + 1;
		(*sortingArray)[n] = value;
	}
}
// Quick sort is too easy for you Klaudia


int Partition(vector<int> &sortingArray, int low, int high)
{
<<<<<<< HEAD
	int pivot = sortingArray[low];
	int from_left = low + 1;
	int from_right = high;
	int tmp;

	while (from_left != from_right) {
		if (sortingArray[from_left] <= pivot) from_left++;
		else {
			while ((from_left != from_right) && (pivot < sortingArray[from_right]))
			{
				from_right--;
			}

			//swap
			tmp = sortingArray[from_right];
			sortingArray[from_right] = sortingArray[from_left];
			sortingArray[from_left] = tmp;
		}
	}

	if (sortingArray[from_left] > pivot) 
		from_left--;
	sortingArray[low] = sortingArray[from_left];
	sortingArray[from_left] = pivot;

	return (from_left);
}

void QuickSort(vector<int> &sortingArray,int low, int high)
{
	if (low < high)
	{
		int pi = Partition(sortingArray, low, high);

		// Separately sort elements before 
		// partition and after partition 
		QuickSort(sortingArray, low, pi - 1);
		QuickSort(sortingArray, pi + 1, high);
	}
=======
	
>>>>>>> master

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
	int firstElement = 0;
	int lastElement = sizeOfArray-1;
	QuickSort(sortingArray, firstElement, lastElement);

	cout << endl;
	return 0;
}