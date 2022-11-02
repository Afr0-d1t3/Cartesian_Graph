#pragma once
//***************************************************************************************
// Title: lines.h
// Course: Computational Problem Solving II
// Developer: Santiago Sanchez
// Date: 10/17/2022
// Purpose: Contains the declarations of the lineType functions
//***************************************************************************************

using namespace std;

class lineType
{
private:
	float a;
	float b;
	float c;
public:
	/***************Member Functions**********************/
	lineType();  //Constructor Default all ones
	void setCoefficient(float q, float w, float e);  //Sets custom coefficients for a line
	void displayLine(); //Displays the requested line
	void lineSlope();  //Finds slope of requested line
	void Intersection(lineType contend);  //Finds where two lines intersect


	/***************Overide Functions**********************/
	bool operator==(lineType contend);  //Sees if two lines are equal
	bool operator||(lineType contend);  //Sees if two lines are parallel
	bool operator&&(lineType contend);  //Sees if two lines are perpendicular

};