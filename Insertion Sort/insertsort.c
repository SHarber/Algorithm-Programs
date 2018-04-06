/***************************************************************************************
* Author: Sarah Harber																   *
* Date: 10/1/17																		   *
* Program: insertionsort.c															   *
***************************************************************************************/
/**************************************************************************************/
/*									File Headers									  */

	#include <fstream>
	#include <string>
	#include <iostream>
	#include <stdio.h>
	#include <stdlib.h>
	#include <cstdlib>
	#include <time.h>
	using namespace std;

/**************************************************************************************/
/*								Function Prototypes									  */
	
	void insertion_sort(int[], int);

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
		for (int i=0; i< size; i++)
			myArray[i] = rand() % 10000 + 0;
		
		clock_t start_time;
		clock_t end_time;
		start_time = clock();
		insertion_sort(myArray, size);
		end_time = clock();
		cout << "Total Duration: " << end_time << "\n";
	}


/**************************************************************************************/
/*								INERTION SORT FUNCTION								  */
/*																					  */
/**************************************************************************************/
	void insertion_sort(int arr[], int length) 
	{
		int j, temp;

		for (int i = 0; i < length; i++) {
			j = i;

			while (j > 0 && arr[j] < arr[j - 1]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				j--;
			}
		}
	}
/*																					  */	
/* REFERENCE: "http://cforbeginners.com/insertionsort.html"							  */
/**************************************************************************************/
