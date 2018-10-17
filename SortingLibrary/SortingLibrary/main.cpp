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
#include <exception>
#include <ctime>
#include <string>

using namespace std;

/*Function that test if the user input is integer*/
int IsInteger(string input) 
{
	int bad = 0;
	//loop of the size of the input
	for (int i = 0; i < input.size(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '.')
			return 0;
		if (input[i] == '.')
			bad++;
		if (input[i] == '-')
			bad++;
	}
	//check if bad contains something
	if (bad)
		return 0;
	//return 1 == true
	return 1;
}
/* Function to print the vector*/
void PrintResult(vector<int> *sortingArray)
{
	int width = 6;
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

		// Move elements of Vector[0..i-1], that are
		// greater than key, to one position ahead
		// of their current position
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
	// The user enters an integer converting in string to check 
	// if the user does not input a wrong input
	string tmpSize;
	cout << "Insert the size of the array: ";
	getline(cin, tmpSize);
	while (!IsInteger(tmpSize))
	{	
		cout << "Wrong input!" << endl;
		cout << "Insert the size of the array: ";
		getline(cin, tmpSize);
	}
	*sizeOfArray = stoi(tmpSize);
}

/*Function that fill array (vector) with random numbers */
void FillArray(vector<int> *sortingArray, int *sizeOfArray)
{
	int value = 0;
	//initialize random seed
	srand(time(NULL));
	for (int n = 0; n < *sizeOfArray; n++)
	{
		//generate secret number between 1 and 100
		value = rand() % 100 + 1;
		(*sortingArray)[n] = value;
	}
}

/* Initialization of index array: from 0 to sizeOfArray */
void FillIndexArray(vector<int> *indexArray, int *sizeOfArray)
{
	for (int i = 0; i < *sizeOfArray; i++)
	{
		(*indexArray)[i] = i;
	}
}

/* Update index array after sorting  */
void GetIndexFromSortedArray(vector<int> *tmpArray, vector<int> *sortingArray, vector<int> *indexArray)
{
	vector<int> indexes((*sortingArray).size());
	for (int i = 0; i < (*sortingArray).size(); i++) 
	{
		for (int j = 0; j < (*sortingArray).size(); j++)
		{
			//if elements are the same, update index
			if ((*tmpArray)[j] == (*sortingArray)[i])
			{
				indexes[i] = j;
				break;
			}
		}
	}

	*indexArray = indexes;
	
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
	//Create arrays for insertion sort
	int sizeOfArray = 0;
	InsertSizeOfArray(&sizeOfArray);
	vector<int> sortingArray(sizeOfArray);	//array for sorted values
	vector<int> tmpArray(sizeOfArray);		//temporary array for unsorted values
	vector<int> indexArray(sizeOfArray);	//array for indexes

	//Fill first array
	FillArray(&sortingArray, &sizeOfArray);
	PrintResult(&sortingArray);
	tmpArray = sortingArray;
	//Print indexes
	FillIndexArray(&indexArray,&sizeOfArray);
	PrintResult(&indexArray);

	cout << endl;

	//Insertion Sort for first array
	clock_t begin = clock();

	insertionSort(&sortingArray, &sizeOfArray);
	
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	PrintResult(&sortingArray);
	//Print indexes
	GetIndexFromSortedArray(&tmpArray, &sortingArray,&indexArray);
	PrintResult(&indexArray);
	cout << "Elapsed time: " << setprecision(10) << elapsed_secs * 1.0e-6 << "sec\n";


	/* QUICKSORT */
	cout << "\nQuick sort \n";

	//Create arrays for quicksort
	int sizeOfArray2 = 0;
	InsertSizeOfArray(&sizeOfArray2);
	vector<int> sortingArray2(sizeOfArray2);//array for sorted values
	vector<int> tmpArray2(sizeOfArray2);		//temporary array for unsorted values
	vector<int> indexArray2(sizeOfArray2);	//array for indexes

	//Fill second array
	FillArray(&sortingArray2, &sizeOfArray2);
	PrintResult(&sortingArray2);
	tmpArray2 = sortingArray2;

	//Print indexes
	FillIndexArray(&indexArray2, &sizeOfArray2);
	PrintResult(&indexArray2);

	cout << endl;

	//Quick Sort
	clock_t begin2 = clock();

	QuickSort(sortingArray2, 0, sizeOfArray2-1);

	clock_t end2 = clock();
	double elapsed_secs2 = double(end2 - begin2) / CLOCKS_PER_SEC;
	PrintResult(&sortingArray2);
	//Print indexes
	GetIndexFromSortedArray(&tmpArray2, &sortingArray2, &indexArray2);
	PrintResult(&indexArray2);
	cout << "Elapsed time: " << setprecision(10) << elapsed_secs2 * 1.0e-6 << "sec\n";

	cout << endl;
	return 0;
}