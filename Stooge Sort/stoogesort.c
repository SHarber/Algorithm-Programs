/***************************************************************************************
* Author: Sarah Harber																   *
* Date: 10/8/17																		   *
* Program: stoogesort.c															   *
***************************************************************************************/
/**************************************************************************************/
/*									File Headers									  */

	#include <fstream>
	#include <string>
	#include <iostream>
	#include <stdio.h>
	#include <stdlib.h>
	#include <cstdlib>
	#include <cmath>
	using namespace std;

/**************************************************************************************/
/*								Function Prototypes									  */
	
	void stooge_sort(int[], int, int);

/**************************************************************************************/
/*									Main Function									  */

	int main()
	{

		// Declare Variables Needed
			ifstream inFile;	// Input File
			ofstream outFile;	// Output File

		// Open Input & Output Files.
			outFile.open("stooge.out");	// Output file name
			inFile.open("data.txt");	// Input file name.

		// If File does not open - Output Error
			if (!inFile)
			{
				std::cout << "Unable to open file data.txt\n";
			}
			else // If File is Open
			{
				string myString; // String to hold line of file

				while (getline(inFile, myString))
				{
				
					// Store each value in an array
					string numVals = myString.substr(0, myString.find(" "));
					string tempString = myString.substr((myString.find(" ") + 1), myString.length());
					int sizeOfLine = atoi(numVals.c_str());
					int needsSorting[sizeOfLine];
					for (int i = 0; i < sizeOfLine; i++)
					{
						string val = tempString.substr(0, tempString.find(" "));
						tempString = tempString.substr(tempString.find(" ") + 1, tempString.length());
						needsSorting[i] = atoi(val.c_str());
					}
					stooge_sort(needsSorting, 0, sizeOfLine-1);

					for (int i = 0; i < sizeOfLine; i++)
					{
						outFile << needsSorting[i] << " ";
					}

					outFile << "\n";
				}



			}
		// Close input & Output File
			inFile.close();
			outFile.close();
	}


/**************************************************************************************/
/*								INERTION SORT FUNCTION								  */
/*																					  */
/**************************************************************************************/
	
/*																					  */	
/**************************************************************************************/
// Function to implement stooge sort
	void stooge_sort(int arr[], int low, int high)
	{
		// If there is less than 2 elements.
		if (low >= high)
			return;

		int temp;
		// If the sub array has more than 2 elements.

		if (high - low + 1 > 2)
		{
			temp = (high - low + 1) / 3;	// Find the element representing 1/3rd of the array.
			stooge_sort(arr, low, high - temp); // Sort the bottom 2/3rds array
			stooge_sort(arr, low + temp, high); // Sort the top 1/3rd of the array
			stooge_sort(arr, low, high - temp); // Sorth the bottom 2/3rds of the array again.
		}

		// Once hte sub array has 2 elements
		if (arr[high] < arr[low])	// Check to see if the high array is smaller than the low array
		{
			swap(arr[high], arr[low]);	// Swap the elements.
		}
		
	}