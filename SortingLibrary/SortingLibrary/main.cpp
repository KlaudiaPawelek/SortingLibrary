

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
{
	int width = 4;
	{
		cout << left << setw(width) << setfill(' ') << (*sortingArray)[i];
	}
	cout << endl;
}
/* Function to sort a vector using insertion sort*/
{
	{
		j = i - 1;

		/* Move elements of Vector[0..i-1], that are
		   greater than key, to one position ahead
		   of their current position */
		{
			j = j - 1;
		}
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
	cin >> tmpSize;
	*sizeOfArray = tmpSize;
}

void FillArray(vector<int> *sortingArray, int *sizeOfArray)
{
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

int Partition(vector<int> &sortingArray, int low, int high)
{
	int pivot = sortingArray[low];
			{
			}

			//swap
		}
	}


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