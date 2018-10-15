#include <iostream>
#include <istream> 
#include <vector>
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

void InsertionSort()
{

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