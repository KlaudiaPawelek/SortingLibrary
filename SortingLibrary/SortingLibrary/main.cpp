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
#include <fstream>

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
		cout << left << setw(6) << setfill(' ') << (*sortingArray)[i];
	}
	cout << endl;
}
/* Function to sort a vector using insertion sort*/
void insertionSort(vector<int> *sortingArray, int *sizeOfArray)
{
	int i = 1;
	int j = 0;
	while (i < *sizeOfArray)
	{
		j = i ;
		// Move elements of Vector[0..i-1], that are
		// greater than key, to one position ahead
		// of their current position
		while (j > 0 && (*sortingArray)[j-1] > (*sortingArray)[j])
		{
			swap((*sortingArray)[j], (*sortingArray)[j - 1]);
			j = j - 1;
		}
		i++;
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
	while (!IsInteger(tmpSize) || tmpSize == "")
	{	
		cout << "Wrong input! Please input an integer: ";
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

int main()
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

	//Insertion Sort algorithm
	clock_t begin = clock(); // performance test start
	insertionSort(&sortingArray, &sizeOfArray);
	clock_t end = clock(); //performance test end
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	
	//Print results
	PrintResult(&sortingArray);
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

	//Quick Sort algorithm
	clock_t begin2 = clock(); //performance test start
	QuickSort(sortingArray2, 0, sizeOfArray2-1);
	clock_t end2 = clock(); //performance test end
	double elapsed_secs2 = double(end2 - begin2) / CLOCKS_PER_SEC;
	
	//Print results
	PrintResult(&sortingArray2);
	SortIndexes(unsortedArray2);
	cout << "Elapsed time: " << elapsed_secs2 << "sec\n";
	cout << endl;

	ofstream outputFile;
	outputFile.open("Data.txt");
	outputFile << fixed << setprecision(10);
	outputFile << left << setw(20) << setfill(' ') << "Size of Array";
	outputFile << left << setw(20) << setfill(' ') << "Insertion sort";
	outputFile << left << setw(20) << setfill(' ') << "Quick sort";
	outputFile << endl;
	if (outputFile.is_open()) {
		for (int i = 0; i <= 200; i += 10)
		{
			sizeOfArray = i*50;
			if (i == 0)
			{
				sizeOfArray = 10;
			}
			outputFile << left << setw(20) << setfill(' ') << sizeOfArray;
			
			vector<int> sortingArray(sizeOfArray);
			FillArray(&sortingArray, &sizeOfArray);
			
			//Insertion Sort for first array
			clock_t begin3 = clock(); //performance test start
			insertionSort(&sortingArray, &sizeOfArray);
			clock_t end3 = clock();  //performance test end
			double elapsed_secs3 = double(end3 - begin3) / CLOCKS_PER_SEC;
			outputFile << left << setw(20) << setfill(' ') << elapsed_secs3;

			//Quick Sort
			clock_t begin4 = clock(); //performance test start
			QuickSort(sortingArray, 0, sizeOfArray - 1);
			clock_t end4 = clock(); //performance test end
			double elapsed_secs4 = double(end4 - begin4) / CLOCKS_PER_SEC;
			outputFile << left << setw(20) << setfill(' ') << elapsed_secs4;

			outputFile << endl;
		}
		outputFile.close();
	}
	return 0;
}