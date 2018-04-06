To compile:

g++ -o change makechange.cpp

./change



Program/Algorithm Information:  
** Algorithm studied: Making Change using Dynamic Programing.
** Input Text: (amount.txt) Each problem should have 2 lines, the first line will have a list of denominations, followed by the total amount.
	Example amount.txt:
		1 2 5
		10
		1 3 7 12
		29
		1 2 4 8
		15

** Output Text: (change.txt) 	Line one: Denomination
				Line two: Total Amount
				Line three: The minimum number of each denomination used.
	Example change.txt:
		1 2 5
		10
		0 0 2
		2
		1 3 7 12
		29
		0 1 2 1
		4
		1 2 4 8
		15
		1 1 1 1
		4