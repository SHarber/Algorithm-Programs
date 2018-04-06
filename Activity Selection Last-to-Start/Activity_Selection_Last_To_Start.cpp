/***************************************************************************************
* Author: 		Sarah Harber																
* Date: 		10/15/17																	
* Program:  	Program to find the minimum number of coins needed to make change for a 
				total and keep track of the optimized solution 					
***************************************************************************************/
/**************************************************************************************/
/*									File Headers									  */

	#include <fstream>
	#include <string.h>
	#include <string> 
	#include <iostream>
	#include <stdio.h>
	#include <stdlib.h>
	#include <cstdlib>
	#include <cmath>
	#include <vector>
	#include <sstream>
	using namespace std;

int DEBUG = 0;

/**************************************************************************************/
/*								Struct Declaration									  */

	struct Activity
	{
		int act_num, start, finish;
	};

/**************************************************************************************/
/*								Function Prototypes									  */

void Merge(Activity *a, int low, int high, int mid);
void MergeSort(Activity *a, int low, int high);


/**************************************************************************************/
/*									Main Function									  */

	int main()
	{
		int set_Count = 0;								// Variable to hold the set count.
		
		// Read in each activity set.
		std::ifstream inputfp("act.txt", ios::in);		// Input stream to file
		while(!inputfp.eof()) 							// While we have not finished all activity sets...
		{
			set_Count++;								// Increase set counter
			int n;										// Variable to hold number of Activities in Set
		   	inputfp >> n;								// Get number of Activities & store in n.
		   	Activity set[n];							// Variable to create an array all actities in the set

		   for (int k = 0; k < n; k++) 					// Loop through the next lines & get the activity number, start time and finish time.
		   {
		      inputfp >> set[k].act_num; 				// Get Activity Number
		      inputfp >> set[k].start;					// Get Start Time 
		      inputfp >> set[k].finish;					// Get Finish Time.
		      if (DEBUG == 1)							// Trace statement
		      	cout << "#: " <<  set[k].act_num << " s: " <<  set[k].start << " f: " <<  set[k].finish << endl;
			}

		  
			// Step 1: Sort the activity set based on Start time in Decending.
			MergeSort(set, 0, n-1);
			if (DEBUG == 1)							// Trace statement
   			   for (int k = 0; k < n; k++) 					// Loop through the next lines & get the activity number, start time and finish time.
		      		cout << "#: " <<  set[k].act_num << " s: " <<  set[k].start << " f: " <<  set[k].finish << endl;
			
		    
		     cout << "Set " << set_Count << endl;		// Output set Number. 
		     int numActivities = 0;						// Initialiaze # of Acitivities Selected.
		     vector<int> selectedActivities;			// Initialize vector for activities selected.
		    
	     	// Step 2:  Select the first activity.
	     		selectedActivities.push_back(set[0].act_num);
	     		Activity lastchosen = set[0];
	     		numActivities++;
	     	// Step 3: Consider the rest of the activities.
	     		for(int j = 1; j < n; j++)
	     		{
	     			// If the finish time of the last activity is
	     			// less than or equal to the start tiem of the
	     			// last activity chosen. 
	     			if(lastchosen.start >= set[j].finish)
	     			{
	     				numActivities++;
	     				lastchosen = set[j];
	     				selectedActivities.push_back(set[j].act_num);
	     			} 
	     		}

	     		cout << "Number of Activities: " << numActivities << endl;
	     		cout << "Activites: ";
	     		for (int i = (selectedActivities.size()-1); i >= 0; i--)
	     		{
	     			cout << selectedActivities[i] << " ";
	     		}
	     		cout << endl;
		}
	}


/**************************************************************************************/
/*								MERGE SORT FUNCTIONS								  */
/*																					  */
/**************************************************************************************/

	// A function to merge the two half into a sorted data.
	void Merge(Activity *a, int low, int high, int mid)
	{
		// We have low to mid and mid+1 to high already sorted.
		int i, j, k; 
		Activity temp[high-low+1];
		i = low;
		k = 0;
		j = mid + 1;
	 
		// Merge the two parts into temp[].
		while (i <= mid && j <= high)
		{
			if (a[i].start > a[j].start)
			{
				temp[k].start= a[i].start;
				temp[k].finish= a[i].finish;
				temp[k].act_num= a[i].act_num;

				k++;
				i++;
			}
			else
			{
				temp[k].start = a[j].start;
				temp[k].finish = a[j].finish;
				temp[k].act_num = a[j].act_num;

				k++;
				j++;
			}
		}
	 
		// Insert all the remaining values from i to mid into temp[].
		while (i <= mid)
		{
			temp[k].start= a[i].start;
			temp[k].finish= a[i].finish;
			temp[k].act_num= a[i].act_num;

			k++;
			i++;
		}
	 
		// Insert all the remaining values from j to high into temp[].
		while (j <= high)
		{
			temp[k].start = a[j].start;
			temp[k].finish = a[j].finish;
			temp[k].act_num = a[j].act_num;

			k++;
			j++;
		}
	 
	 
		// Assign sorted data stored in temp[] to a[].
		for (i = low; i <= high; i++)
		{
			a[i].start = temp[i-low].start;
			a[i].finish = temp[i-low].finish;
			a[i].act_num = temp[i-low].act_num;
		}
	}
 
	// A function to split array into two parts.
	void MergeSort(Activity *a, int low, int high)
	{
		int mid;
		if (low < high)
		{
			mid=(low+high)/2;
			// Split the data into two half.
			MergeSort(a, low, mid);
			MergeSort(a, mid+1, high);
	 
			// Merge them to get sorted output.
			Merge(a, low, high, mid);
		}
	}
 
// Reference: http://www.sanfoundry.com/cpp-program-implement-merge-sort/
/**************************************************************************************/
