/*
2297037
Chase Tullar
CPSC350
Assignment 6
11/29/18
*/
#include <iostream>
#include <fstream>
#include <ctime>
#include "Sort.h"
using namespace std;

Sort::Sort()
{
	//constr
	path;
	piles;
	openr;
	inData = 0;

	k = -1;
}

Sort::~Sort()
{
	//destr
	cout << "Assortment destroyed" << endl;
}

void Sort::ReadInfo(string path)
{
	//read in info

	openr.open(path); //open filepath

	openr >> piles; //create amnt of sorting piles from file (1st inread)

	double arr[piles];

	cout << "Number of items: " << piles << endl;

	//read in data
	if (openr.is_open())
	{
		
		while (openr >> inData) //put read in doubles in array
		{
			++k;

			if (k < piles)
			{
				
				arr[k] = inData; //add data to array

				cout << "arr[" << k << "] " << arr[k] << endl; //print
			}
			
			
		}

	}

	//low/high vars for quickSort
	low = arr[0];
	high = arr[k];

	//execute sorting
	bubbleSort(arr, piles);
	quickSort(arr, high, low);
	insertSort(arr, piles);
	selectSort(arr, piles);

	
}


void Sort::bubbleSort(double myArray[], double p) //BUBBLESORT
{
	clock_t startTime = clock();

	cout << "doubleSorted List" << endl;

	int m = 0;

	bool swapped; //tell if swap

	for (int i = 0; i < p-1; ++i)
	{
		swapped = false; //reset

		for(int j = 0; j < p-i-1; ++j)
		{
			if (myArray[j] > myArray[j+1]) //swap if larger
			{
				swap(&myArray[j], &myArray[j+1]);
				swapped = true;
			}

		}

		if(!swapped)
		{
			break; //already swap
		}
	}

	clock_t endTime = clock();

	clock_t duration = double(endTime - startTime)/CLOCKS_PER_SEC*1000;

	cout << "Time taken: " << duration << " ms" << endl;

	while(m < p) //print results
	{
		cout << myArray[m] << endl;
		++m;
	}
	
}

void Sort::swap(double *xp, double *yp) //function to swap vars in array
{
	double temp = *xp;
	*xp = *yp;
	*yp = temp;
}

double Sort::quickSort(double myArray[], double h, double l) //QUICKSORT
{
	cout << "Quick Sorted Data" << endl;

	clock_t startTime = clock();

	double pivot = high;
	int lower = low - 1; //might brake

	for(int j = low; j <= high-1; ++j)
	{
		if(myArray[j] <= pivot) //sort based on pivot comparisons
		{
			++lower;

			swap(&myArray[lower], &myArray[j]); //swap
		}
	}

	swap(&myArray[lower + 1], &myArray[high]);

	printArray(myArray, piles); //print results

	clock_t endTime = clock();

	clock_t duration = double(endTime - startTime)/CLOCKS_PER_SEC*1000;

	cout << "Time taken: " << duration << " ms" << endl;
	//printArray(myArray, piles); //print

	return (lower + 1);
}

void Sort::quick(double myArray[], double h, double l)
{
	clock_t startTime = clock();

	//function to extend quicksort to swap vars
	if (low < high)
	{
		double part = quickSort(myArray, low, high);

		quick(myArray, low, part - 1);
		quick(myArray, part + 1, high);
	}

	clock_t endTime = clock();

	clock_t duration = double(endTime - startTime)/CLOCKS_PER_SEC*1000;

	//cout << "Time taken: " << duration << " ms" << endl;

	//printArray(myArray, piles); //print
}

void Sort::printArray(double myArray[], double p) //print, used for quickSort
{
	for(int i = 0; i < p; ++i)
	{
		cout << myArray[i] << endl;
	}
}


void Sort::insertSort(double myArray[], double p) //INSERTSORT
{
	cout << "Insertion Sorted Data" << endl;

	clock_t startTime = clock();

	int i;
	int j;
	double key;

	//printVars
	int y = 0;

	for(i = 1; i < p; ++i)
	{
		key = myArray[i];

		j = i-1;

		while(j >= 0 && myArray[j] > key) //insert var back
		{
			myArray[j+1] = myArray[j];
			j = j-1;
		}

		myArray[j+1] = key;
	}

	clock_t endTime = clock();

	clock_t duration = double(endTime - startTime)/CLOCKS_PER_SEC*1000;

	cout << "Time taken: " << duration << " ms" << endl;

	while(y < p) //print results
	{
		cout << myArray[y] << endl;
		++y;
	}
}

void Sort::selectSort(double myArray[], double p)
{
	cout << "Selection Sorted Data" << endl;

	clock_t startTime = clock();

	int i, j;
	int big;

	int y = 0; //printing

	for(i = 0; i < p-1; ++i)
	{
		big = i;

		for(j = i+1; j < p; ++j)
		{
			if(myArray[j] < myArray[big]) //check if val bigger
			{
				big = j;
			}
		}

		swap(&myArray[big], &myArray[i]); //swap if needed
	}

	clock_t endTime = clock();

	clock_t duration = double(endTime - startTime)/CLOCKS_PER_SEC*1000;

	cout << "Time taken: " << duration << " ms" << endl;

	while(y < p) //print data
	{
		cout << myArray[y] << endl;
		++y;
	}
}


