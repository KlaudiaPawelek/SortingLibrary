// C++ program for sorting values

#include <iostream>
#include <iomanip>       /*setw, setfill*/
#include <istream> 
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdio.h> 
#include <math.h> 

using namespace std;

/* Function to print the vector*/
void PrintResult(vector<int> *V)
{
	int width = 4;
	for (unsigned int i = 0; i < (*V).size(); i++) {
		cout << left << setw(width) << setfill(' ') << (*V)[i];
	}
	cout << endl;
}
/* Function to sort a vector using insertion sort*/
void insertionSort(vector<int> *V, int *n)
{
	int i, key, j;
	for (i = 1; i < *n; i++)
	{
		key = (*V)[i];
		j = i - 1;

		/* Move elements of Vector[0..i-1], that are
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
/*Function that asks the user about the size of the vector/array*/
void InsertSizeOfArray(int *sizeOfArray)
{
	int tmpSize = 0;
	cout << "Insert the size of the array: \n";
	/*The user enters an integer*/
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
		//generate secret number between 1 and 100
		value = rand() % 100 + 1;
		(*sortingArray)[n] = value;
	}
}

// Quick sort is too easy for you Klaudia
int Partition(vector<int> &sortingArray, int low, int high)
{
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
}


int main()
{
	cout << "Insertion sort \n";
	//Create first array
	int sizeOfArray = 0;
	InsertSizeOfArray(&sizeOfArray);
	vector<int> sortingArray(sizeOfArray);

	//Fill first array
	FillArray(&sortingArray, &sizeOfArray);

	//Insertion Sort for first array
	insertionSort(&sortingArray, &sizeOfArray);
	PrintResult(&sortingArray);

	cout << "\nQuick sort \n";

	//Create second array
	int sizeOfArray2 = 0;
	InsertSizeOfArray(&sizeOfArray2);
	vector<int> sortingArray2(sizeOfArray2);

	//Fill second array
	FillArray(&sortingArray2, &sizeOfArray2);

	//Quick Sort
	int firstElement2 = 0;
	int lastElement2 = sizeOfArray2-1;
	QuickSort(sortingArray2, firstElement2, lastElement2);
	PrintResult(&sortingArray2);

	cout << endl;
	return 0;
}