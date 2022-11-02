#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include "lines.h"

#define NUM_OF_LINES 4
using namespace std;
//***************************************************************************************
// Title: cartesian_plane.cpp
// Course: Computational Problem Solving II
// Developer: Santiago Sanchez (Main by Professor Zion)
// Date: 10/17/2022
// Purpose: Uses the lineType class to do calculations on the cartesian plane
//***************************************************************************************

int main() {
	bool quit = false;
	float a, b, c;
	int choise;
	int line_select_1, line_select_2;
	vector<lineType> myLines(NUM_OF_LINES);

	do {
		system("pause"); //Pauses the screen and waits for input
		system("cls");  //Clears screen
		//The options that users can use
		cout << "Select which you would like to do:" << endl;
		cout << "1) Set" << endl;
		cout << "2) Display Line" << endl;
		cout << "3) Display ALL Lines" << endl;
		cout << "4) Slope" << endl;
		cout << "5) Equal" << endl;
		cout << "6) Parallel" << endl;
		cout << "7) Perpendicular" << endl;
		cout << "8) Intersection" << endl;
		cout << "9) Quit" << endl;  //Exits loop

		cin >> choise;
		switch (choise) {
		case 0: // debug mode for quick setting
				myLines.at(0).setCoefficient(10, 20, 30);
				myLines.at(1).setCoefficient(10, 20, 30);
				myLines.at(2).setCoefficient(20, 40, 60);
				myLines.at(3).setCoefficient(5, 10, 15);
				break;
		case 1: // set
				cout << "which line would you like to work with: [0.." << NUM_OF_LINES - 1 << "]" << endl;  //Select which line
				cin >> line_select_1;

				cout << "please type in the value:" << endl;
				cout << "a = "; cin >> a;  //Coefficent of x
				cout << "b = "; cin >> b;  //Coefficent of y
				cout << "c = "; cin >> c;  //Constant
				myLines.at(line_select_1).setCoefficient(a, b, c);  //Sets the values
				myLines.at(line_select_1).displayLine();  //Displays final equation
				break;
		case 2: // display line
				cout << "which line would you like to displa: [0.." << NUM_OF_LINES - 1 << "]" << endl;  //Select which line
				cin >> line_select_1;  //User input
				myLines.at(line_select_1).displayLine();
				break;
		case 3: // display ALL lines
				for (int i = 0; i < NUM_OF_LINES; i++)
					myLines.at(i).displayLine();
				break;
		case 4: // slope
				cout << "which line would you like to work with: [0.." << NUM_OF_LINES - 1 << "]" << endl;  //Select which line
				cin >> line_select_1;  //User input
				myLines.at(line_select_1).displayLine();  //Displays final equation
				myLines.at(line_select_1).lineSlope();  //Function to calculate slope of line
				break;
		case 5: // equal
				cout << "select the first line: [0.." << NUM_OF_LINES - 1 << "]" << endl;
				cin >> line_select_1;  //User input
				myLines.at(line_select_1).displayLine();  //Displays equation of first
				cout << "select the second line: [0.." << NUM_OF_LINES - 1 << "]" << endl;
				cin >> line_select_2;  //User input
				myLines.at(line_select_2).displayLine();  //Displays equation of second
				if (myLines.at(line_select_1) == myLines.at(line_select_2)) {  //Compares if the lines are equal
					cout << "these two lines are EQUAL" << endl;
				}
				else {
					cout << "these two lines are NOT EQUAL" << endl;
				}
				break;
		case 6: // parallel
				cout << "select the first line: [0.." << NUM_OF_LINES - 1 << "]" << endl;  //Select which line
				cin >> line_select_1;  //User input
				myLines.at(line_select_1).displayLine();  //Displays equation of first

				cout << "select the second line: [0.." << NUM_OF_LINES - 1 << "]" << endl;  //Select which line
				cin >> line_select_2;  //User input
				myLines.at(line_select_2).displayLine();  //Displays equation of first

				if (myLines.at(line_select_1) || myLines.at(line_select_2)) {  //Compares the two lines to see if they are parallel
					cout << "these two lines are PARALLEL" << endl;
				}
				else {
					cout << "these two lines are NOT PARALLEL" << endl;
				}
				break;
		case 7: // perpendicular
				cout << "select the first line: [0.." << NUM_OF_LINES - 1 << "]" << endl;  //Select which line
				cin >> line_select_1;  //User input
				myLines.at(line_select_1).displayLine();  //Displays equation of first

				cout << "select the second line: [0.." << NUM_OF_LINES - 1 << "]" << endl;  //Select which line
				cin >> line_select_2;  //User input
				myLines.at(line_select_2).displayLine();  //Displays equation of second

				if (myLines.at(line_select_1) && myLines.at(line_select_2)) {  //Compares the two lines to see if they are perpendicular
					cout << "these two lines are PERPENDICULAR" << endl;
				}
				else {
					cout << "these two lines are NOT PERPENDICULAR" << endl;
				}
				break;
		case 8: // intersection
				cout << "select the first line: [0.." << NUM_OF_LINES - 1 << "]" << endl;  //Select which line
				cin >> line_select_1;  //User input
				myLines.at(line_select_1).displayLine();  //Displays equation of first

				cout << "select the second line: [0.." << NUM_OF_LINES - 1 << "]" << endl;  //Select which line
				cin >> line_select_2;  //User input
				myLines.at(line_select_2).displayLine();  //Displays equation of second
				myLines.at(line_select_1).Intersection(myLines.at(line_select_2));  //Calculates the point at which two lines intersect
				break;
		case 9: //quit
				quit = true;
				break;
		case 10: //Testing slope 
			myLines.at(0).setCoefficient(20, 10, 30);  // -2
			myLines.at(1).setCoefficient(-30, 5, 30);  // 6
			myLines.at(2).setCoefficient(0, 10, 60);  // Horizontal
			myLines.at(3).setCoefficient(-10, 0, 15);  //Vertical
			break;
		case 11: //Testing Parallel 
			myLines.at(0).setCoefficient(20, 10, 30);  // -2
			myLines.at(1).setCoefficient(40, 20, 30);  // -2
			myLines.at(2).setCoefficient(0, 10, 60);  // Horizontal
			myLines.at(3).setCoefficient(0, 8, 15);  // Horizontal
			break;
		case 12: //Testing Perpendicular 
			myLines.at(0).setCoefficient(0, 10, 30);  // Horizontal
			myLines.at(1).setCoefficient(40, 0, 30);  // Vertical
			myLines.at(2).setCoefficient(0.2, 1, 60);  // -0.2
			myLines.at(3).setCoefficient(-5, 1, 15);  // 5
			break;
		case 13: //Testing Intersect 
			myLines.at(0).setCoefficient(0, 1, 30);  // y = 30
			myLines.at(1).setCoefficient(1, 0, 40);  // x = 40
			myLines.at(2).setCoefficient(-5, 1, 30);  // y = 5x + 30
			myLines.at(3).setCoefficient(-2, 1, 0);  // y = 2x + 30  (-10,-20) with Line2
			break;
		}
		

	} while (!quit);  //Exits after quit is set to true

	return 0;
}
