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
#include <algorithm>
#include <numeric>

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
	srand(static_cast<unsigned int>(time(NULL)));
	for (int n = 0; n < *sizeOfArray; n++)
	{
		//generate secret number between -100 and 100
		
		value = rand() % 101 + (-50);
		(*sortingArray)[n] = value;
	}
}

template <typename T>
void SortIndexes(const vector<T> &unsortedArray) {

	// initialize original index locations
	vector<size_t> index(unsortedArray.size());
	iota(index.begin(), index.end(), 0);

	// sort indexes based on comparing values in v
	sort(index.begin(), index.end(), 
		[&unsortedArray](size_t i1, size_t i2) {return unsortedArray[i1] < unsortedArray[i2]; });
	
	//print indexes
	cout << "index after sorting: \n";
	for (int i = 0; i < index.size(); i++)
	{
		cout << left << setw(6) << setfill(' ') << index[i];
	}
	cout << endl;
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
/* TEST */

/* Check, if array is empty */
/* sortingArray - insertion sort, sortingArray2 - quicksort */
void isEmpty(vector<int> &sortingArray, vector<int> &sortingArray2)
{
	cout<<"Is array for insertion sort empty? "<< boolalpha<<sortingArray.empty()<<endl;
	cout << "Is array for quicksort empty? " << boolalpha<<sortingArray.empty()<<endl;
}
/* Check, if array is sorted */
bool isSorted(vector<int> &sortingArray, int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	if (sortingArray[n - 1] < sortingArray[n - 2])
	{
		return 0;
	}
	return isSorted(sortingArray, n - 1);
}


int main()
{
	try
	{
		cout << fixed << setprecision(20);
		/* INSERTION SORT */
		cout << "Insertion sort \n";
		//Create arrays for insertion sort
		int sizeOfArray = 0;
		InsertSizeOfArray(&sizeOfArray);
		vector<int> sortingArray(sizeOfArray);	//array for sorted values
		vector<int> unsortedArray(sizeOfArray);		//temporary array for unsorted values

		//Fill first array
		FillArray(&sortingArray, &sizeOfArray);
		PrintResult(&sortingArray);
		unsortedArray = sortingArray;

		clock_t begin = clock(); // performance test start

		//Insertion Sort for first array
		insertionSort(&sortingArray, &sizeOfArray);

		clock_t end = clock(); //performance test end
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		PrintResult(&sortingArray);

		//Print indexes
		SortIndexes(unsortedArray);

		cout << "Elapsed time: " << elapsed_secs << "sec\n";

		/* QUICKSORT */
		cout << "\nQuick sort \n";

		//Create arrays for quicksort
		int sizeOfArray2 = 0;
		InsertSizeOfArray(&sizeOfArray2);
		vector<int> sortingArray2(sizeOfArray2);//array for sorted values
		vector<int> unsortedArray2(sizeOfArray2);		//temporary array for unsorted values

		//Fill second array
		FillArray(&sortingArray2, &sizeOfArray2);
		PrintResult(&sortingArray2);
		unsortedArray2 = sortingArray2;
		cout << endl;


		clock_t begin2 = clock(); //performance test start

		//Quick Sort
		QuickSort(sortingArray2, 0, sizeOfArray2 - 1);

		clock_t end2 = clock(); //performance test end
		double elapsed_secs2 = double(end2 - begin2) / CLOCKS_PER_SEC;
		PrintResult(&sortingArray2);
		//Print indexes
		SortIndexes(unsortedArray2);

		cout << "Elapsed time: " << elapsed_secs2 << "sec\n";

		cout << endl << "TEST" << endl;
		isEmpty(sortingArray, sortingArray2);
		cout << "\nIs array for insertion sort sorted? " << boolalpha << isSorted(sortingArray, sortingArray.size());
		cout << "\nIs array for quicksort sorted? " << boolalpha << isSorted(sortingArray2, sortingArray2.size());
	}
	catch (exception &e)
	{
		cout << "Sorry. Something went wrong! " << e.what();
	}
	
	cout << endl;
	return 0;
}