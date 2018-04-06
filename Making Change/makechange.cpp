/***************************************************************************************
* Author: 		Sarah Harber																
* Date: 		10/15/17																	
* Program:  	Program to find the minimum number of coins needed to make change for a 
				total and keep track of the optimized solution 					
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
	#include <vector>
	#include <sstream>
	using namespace std;


/**************************************************************************************/
/*								Function Prototypes									  */
	
	vector<int> makeChange(vector<int> C, int change);
	
/**************************************************************************************/
/*									Main Function									  */

	int main()
	{
		// Declare Variables Needed For File Stream
			ifstream inFile;	// Input File
			ofstream outFile;	// Output File

		// Declare Variables Needed For Input From File
			vector<string> input;		// Vector to store the lines from input file.
			vector<int>	denominations;	// Vector to store the denominations from input file.
			int amount;					// Variable to store the amount needed in change.



		// Open Input & Output Files.
			outFile.open("change.txt");	// Output file name
			inFile.open("amount.txt");	// Input file name.

		// Check to make sure both Input & Output files have opened. 
			if(!outFile)										// If Output file did not open
			{
				std::cout << "Unable to open output file\n";	// Display error message
				return 1;										// Return stats 1.
			}
			else if (!inFile)									// If Input file did not open
			{
				std::cout << "Unable to open input file\n";		// Display error message
				return 2;										// Return stats 2.

			}
			else 												// If both files oppened
			{
				// Get all the lines from the input file.  Store in vector input.
				string line;					// Variable to hold each line.
				while(getline(inFile, line))	// Get a line until eof.
				{
					if(!line.empty()); 			// If the line is not blank.
						input.push_back(line);	// Add line to the vector.
				}

				// Calculate all the change cases in the vector.
				for(int i = 0; i < input.size(); i++)
				{
					//Write first 2 lines to Output File.
					outFile << input[i] << "\n" << input[i+1] << "\n"; 	// Writes denominations to output file.
					
					// Store amount needed for change in variable (declared above).
					amount = atoi(input[i+1].c_str());
					
					string str = input[i];		// Assign input to a string
					string buf; 				// Have a buffer string
				    stringstream ss(str); 		// Insert the string into a stream
				    vector<string> tokens;		// Create vector to hold our words

				    while (ss >> buf)			// Read string in to buffer
				        tokens.push_back(buf);	// Put buffer in vector

				    for(int a=0; a<tokens.size(); a++)		// For all tokens
				    {
				    	denominations.push_back(atoi(tokens[a].c_str()));	// Convert to integers adn store in denominations
				    }

				    vector<int> count = makeChange(denominations, amount);	// Calculate the minimum number of each coins needed and store in vector to write to file.
				  	i++; 	// Increase i.
				  	denominations.clear();		// Clear denominations vector

				  	for(int d = 0; d < count.size(); d++)	
				  		outFile << count[d] << " " ;			// Write all counts to the file

				  	outFile << "\n";							// Add new line character to end of this set.
				}
			}
			// Close input & Output File
			inFile.close();
 			outFile.close();
	}


/**************************************************************************************/
/*								Make Change Function							  	  */

vector<int> makeChange(vector<int> C, int change)
{
    vector<int> S(change + 1,1000);
    vector<int> seq(change + 1);
    vector<int> count;

    // Create count array that is the same size as C.
    for (int l = 0; l < C.size(); l++)
    	count.push_back(0);

    // Base Case when change = 0.
    S[0] = 0;

    // For all amounts less than change
    for(int i = 1; i < change + 1; i++)
    {
        for(int j =0;j<C.size(); j++)
        {
            if(i >= C[j] && 1 + S[i-C[j]] < S[i])
            {
                S[i] = 1 + S[i - C[j]];
                seq[i] = j;
                
            }
        }
    }

    // Store proper coin couts in cout.
    int j = change;
    while(j)
    {
    	for(int d = 0; d < C.size(); d++)
        {
                	if(C[seq[j]] == C[d])
                		count[d]++;
         }
        j = j - C[seq[j]];
    }
    

   	return count;

}

