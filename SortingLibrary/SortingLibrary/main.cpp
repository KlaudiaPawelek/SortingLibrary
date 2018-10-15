#include <iostream>
#include <istream> 
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

void PrintResult()
{
	
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

void InsertionSort()
{

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