/* C++ program for sorting values
Sorting algorithm:
1. Insertion sort
2. Quick sort
Vectors are used to storing values.
*/


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
void PrintResult(vector<int> *sortingArray)
{
	int width = 4;
	for (unsigned int i = 0; i < (*sortingArray).size(); i++) 
	{
		cout << left << setw(width) << setfill(' ') << (*sortingArray)[i];
	}
	cout << endl;
}
/* Function to sort a vector using insertion sort*/
void insertionSort(vector<int> *sortingArray, int *sizeOfArray)
{
	int i, key, j = 0;
	for (i = 1; i < *sizeOfArray; i++)
	{
		key = (*sortingArray)[i];
		j = i - 1;

		/* Move elements of Vector[0..i-1], that are
		   greater than key, to one position ahead
		   of their current position */
		while (j >= 0 && (*sortingArray)[j] > key)
		{
			(*sortingArray)[j + 1] = (*sortingArray)[j];
			j = j - 1;
		}
		(*sortingArray)[j + 1] = key;
	}
}
/*Function that asks the user about the size of the vector/array*/
void InsertSizeOfArray(int *sizeOfArray)
{
	int tmpSize = 0;
<<<<<<< HEAD
	cout << "Insert the size of the array: \n";
=======
>>>>>>> Klaudia
	/*The user enters an integer*/
	cout << "Insert size of the input sequence: ";
	cin >> tmpSize;
	*sizeOfArray = tmpSize;
}

/*Function that fill array (vector) with random numbers */
void FillArray(vector<int> *sortingArray, int *sizeOfArray)
{
	int value = 0;
	//initialize random seed
	srand(time(NULL));
<<<<<<< HEAD
=======

>>>>>>> Klaudia
	for (int n = 0; n < *sizeOfArray; n++)
	{
		//generate secret number between 1 and 100
		value = rand() % 100 + 1;
		(*sortingArray)[n] = value;
	}
}

/*Partition method - this is important part of quicksort method*/
int Partition(vector<int> &sortingArray, int low, int high)
{
	int pivot = sortingArray[low];
	int fromLeft = low + 1;
	int fromRight = high;
	int tmp = 0;

	while (fromLeft != fromRight)
	{
		if (sortingArray[fromLeft] <= pivot) 
		{
			fromLeft++;
		}
		else 
		{
			while ((fromLeft != fromRight) && (pivot < sortingArray[fromRight]))
			{
				fromRight--;
			}

			//swap
			tmp = sortingArray[fromRight];
			sortingArray[fromRight] = sortingArray[fromLeft];
			sortingArray[fromLeft] = tmp;
		}
	}

	if (sortingArray[fromLeft] > pivot)
	{
		fromLeft--;
	}
	sortingArray[low] = sortingArray[fromLeft];
	sortingArray[fromLeft] = pivot;

	return (fromLeft);
}

/*Quicksort - main method, which used Partition method and recursion*/
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
	/* INSERTION SORT */
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



	/* QUICKSORT */
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