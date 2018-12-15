/*
2297037
Chase Tullar
CPSC350
Assignment 6
11/29/18
*/
//Sorting class
#include <iostream>
#include <fstream>
using namespace std;

class Sort
{
	public:
		Sort(); //constr
		~Sort(); //destr

		//methods
		double quickSort(double myArray[], double h, double l); //QUICK
		void quick(double myArray[], double h, double l); //quick extension

		void bubbleSort(double myArray[], double p); //BUBBLE
		void insertSort(double myArray[], double p); //INSERT
		void selectSort(double myArray[], double p); //SELECT

		void printArray(double myArray[], double p); //printing used for quickSort

		void swap(double *xp, double *yp); //funct to swap vars

		void ReadInfo(string path); //read in doubles

		//vars
	private:
		int piles; //# of piles of sorting
		double inData; //read in
		//array
		string path;
		ifstream openr;

		int high; //quickSort high var
		double low; //QS low var

		int k;




};