#include <cmath>
#include <iostream>
#include <iomanip>
#include "lines.h"
//***************************************************************************************
// Title: lines.cpp
// Course: Computational Problem Solving II
// Developer: Santiago Sanchez
// Date: 10/17/2022
// Purpose: Contains the calculations of the lineType functions
//***************************************************************************************

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: lineType() (Constructor)
// Input: None
// Output: Sets the data members to default (All 1.0)
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
lineType::lineType()
{
	a = 1.0;
	b = 1.0;
	c = 1.0;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: setCoefficient()
// Input: q, w, e 
// Set values of a, b, c (Correseponding order)
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lineType::setCoefficient(float q, float w, float e)  
{
	a = q;
	b = w;
	c = e;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: displayLine()
// Input: None
// Output: Displays in point-slope form the line
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lineType::displayLine()
{
	cout << fixed << setprecision(2) << setw(8) << a << " x + " << b << " y = "
		<< c << endl;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: lineSlope()
// Input: None
// Output: Displays the slope of the line
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lineType::lineSlope()  
{
	float slope;
	if (b == 0)  //Vertical lines have infinite slope b = 0
	{
		cout << "Slope: Vertical" << endl;
	}
	else if (a == 0)  //Horizontal lines have no slope a = 0
	{
		cout << "Slope: Horizontal" << endl;
	}
	else //Actual slope value
	{
		slope = (-a / b);  ///Divides a/b
		cout << fixed << setprecision(2) << "Slope: " << slope << endl;
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: lineIntersection()
// Input: None
// Output: Calculates where two lines intersect and displays
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lineType::Intersection(lineType contend)
{
	float x; float y;  //Coords declarations
	x = -((b * (contend.c)) - ((contend.b) * c)) / ((a * (contend.b)) - ((contend.a) * b));
	y = -((c * (contend.a)) - ((contend.c) * a)) / ((a * (contend.b)) - ((contend.a) * b));

	cout << fixed << setprecision(2) << setw(5)
		<< "Lines intersect at (" << x << ", "
		<< y << ")" << endl;
}


///***************Overide Functions**********************/

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Overloading '==' Function
// Checks to see if two lines are equal
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool lineType::operator==(lineType contend)  //Sees if two lines are equal
{
	float aKangaroo = (a / contend.a);
	float bKangaroo = (b / contend.b);
	float cKangaroo = (c / contend.c);  //K values of all a, b, and c
	if ((aKangaroo == bKangaroo) && (aKangaroo == cKangaroo))  //if all K values are equal
	{
		return true;
	}
	else { return false; }
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Overloading '||' Function
// Checks to see if two lines are parallel to each other
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool lineType::operator||(lineType contend)  //Sees if two lines are parallel
{
	float primeSlope;  //Slopes of respective numbers
	float contendSlope;
	if ((a == 0) && (contend.a == 0))  //Both Horizontal 
	{
		return true;
	}
	else if ((b == 0) && (contend.b == 0))  //Both vertical
	{
		return true;
	}
	else
	{
		primeSlope = (-a / b);
		contendSlope = (-(contend.a / contend.b));
		if (primeSlope == contendSlope)
		{
			return true;
		}
		else { return false; }
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Overloading '&&' Function
// Checks to see if two lines are perpendicular to each other
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool lineType::operator&&(lineType contend)  //Sees if two lines are perpendicular
{
	float primeSlope;  //Slopes of respective numbers
	float contendSlope;
	if (((a == 0) && (contend.b == 0)) || ((b == 0) && (contend.a == 0)))  //Checks to see if they are horizontal and vertical
	{
		return true;
	}
	else
	{
		primeSlope = (-a / b);
		contendSlope = (-(contend.a / contend.b));  //Calculates slowly
		if ((primeSlope * contendSlope) == -1)  //Should be the negative reciprocal
		{
			return true;
		}
		else { return false; }
	}
}