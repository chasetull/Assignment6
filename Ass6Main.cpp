/*
2297037
Chase Tullar
CPSC350
11/29/18
*/
#include "Sort.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
	//main

	string path; //intake vals

	cout << "Welcome to the Data Sorting Machine" << endl;
	cout << "Enter the file path of the data to be sorted: (doubleFile.txt)" << endl;
	cin >> path; //intake path

	while (path != "doubleFile.txt") //error check
	{
		cout << "Wrong file, try again:" << endl;
		cin >> path;
	}

	Sort *inSort = new Sort(); //instance to use sorting algs

	inSort->ReadInfo(path); //read in data and sort




}