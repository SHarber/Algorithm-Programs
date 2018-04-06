/***************************************************************************************
* Author: Sarah Harber																   *
* Date: 10/1/17																		   *
* Program: mergesort.c															   *
***************************************************************************************/
/**************************************************************************************/
 /*									File Headers									  */

	#include <fstream>
	#include <string>
	#include <iostream>
	#include <stdio.h>
	#include <stdlib.h>
	#include <cstdlib>
	using namespace std;

/**************************************************************************************/
/*								Function Prototypes									  */

	void merge(int a[], int left_low, int left_high, int right_low, int right_high);
	void merge_sort(int a[], int low, int high);
	void merge_sort(int a[], int length);

/**************************************************************************************/
/*									Main Function									  */

	int main()
	{

		// How big should the array be?
		int size;

		cout << "Enter size of array: ";
		cin >> size;
		cout << "\n";

		// Declare Array
		int myArray[size];
		srand((unsigned)time(0));

		// Fill Array
		for (int i = 0; i< size; i++)
			myArray[i] = rand() % 10000 + 0;

		clock_t start_time;
		clock_t end_time;
		start_time = clock();
		merge_sort(myArray, size);
		end_time = clock();
		cout << "Total Duration: " << end_time << "\n";
	}

/**************************************************************************************/
/*								MERGE SORT FUNCTIONS								  */
/*																					  */
/**************************************************************************************/

	void merge_sort(int a[], int length) {
		merge_sort(a, 0, length - 1);
	}

	void merge_sort(int a[], int low, int high) {
		if (low >= high)                  //Base case: 1 value to sort->sorted
			return;                         //(0 possible only on initial call)
		else {
			int mid = (low + high) / 2;       //Approximate midpoint*
			merge_sort(a, low, mid);        //Sort low to mid part of array
			merge_sort(a, mid + 1, high);     //Sort mid+1 to high part of array
			merge(a, low, mid, mid + 1, high); //Merge sorted subparts of array
		}
	}

	void merge(int a[], int left_low, int left_high, int right_low, int right_high)
	{
		int length = right_high - left_low + 1;
		int temp[length];
		int left = left_low;
		int right = right_low;
		for (int i = 0; i < length; ++i) {
			if (left > left_high)
				temp[i] = a[right++];
			else if (right > right_high)
				temp[i] = a[left++];
			else if (a[left] <= a[right])
				temp[i] = a[left++];
			else
				temp[i] = a[right++];
		}

		for (int i = 0; i< length; ++i)
			a[left_low++] = temp[i];
	}
/*																					  */
/* REFERENCE: "https://www.cprogramming.com/tutorial/computersciencetheory/merge.html"							  */
/**************************************************************************************/
