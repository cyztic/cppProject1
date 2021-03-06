/***************************************************************** PROGRAM IDENTIFICATION ***************************************************************************
 *  PROGRAMMER: Josh Wheeler
 *  DATE: 1/23/2018
 *  FILE NAME: Program1.cpp
 *  ASSIGNMENT #: 1
 *
 *  DISCRIPTION: This program is intended to read input from the user, process the data and output it into an HTML file. The data entered by the user will be
 *               float numbers that will be assorted into an HTML table.
 *
 *  OUTPUT FILES: project1.html
 *
 *  COURSE: CSC24400
 *  INSTRUCTOR: Dr. Lawrence Miller
 *  SECTION: 21
 ******************************************************************************************************************************************************************/
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

//Function prototypes
void Header();
void openDocument();
void outputHeader();
void outputOpenTable();
void outputCloseTable();
void closeDocument();
void Footer(int size, float mean, float var, float sDev);
void UserInput();
float MaxValue(float current, float max);
float MinValue(float current, float min);
float Squaring(float current);
void TableData(int counter, float current,float squared, float sum, float squaredSum, float max, float min);
float Mean(float sum, int size);
float Variance(float squaredSum, float sum, int size);
float StandardDeviation(float variance);
//*****************************************************************************************************************************************************************
int main()
{
	openDocument();
	Header();
	outputHeader();
	outputOpenTable();
	UserInput();

	return 0;
}

//RECIEVES: Nothing
//TASK: Creates the header of my program with my name and class information
//RETURNS: Nothing
void Header()
{
	cout << "Josh Wheeler CSC 24400 Section 21 <br>" << endl;
	cout << "Spring 2018 Assignment Project 1 <br>" << endl;
	cout << "<br><hr><br><br>" << endl;
}

//RECIEVES: Nothing
//TASK: Prints code the console to start my HTML tags
//RETURNS: Nothing
void openDocument()
{
	cout << "<!DOCTYPE html>" << endl;
	cout << "<head>" << endl;
	cout << "<title> Project 1 </title>" << endl;
	cout << "</head>" << endl;
	cout << "<body>" << endl;
}

//RECIEVES: Nothing
//TASK: Prints the title of my table
//RETURNS: Nothing
void outputHeader()
{
   cout << "<h1>Standard Deviation Tutorial</h1><br><br>" << endl;
}

//RECIEVES: Nothing
//TASK: Prints the tags to start my table and sets the amount of columns i will be using in the table
//RETURNS: Nothing
void outputOpenTable()
{
   cout << "<table border=\"1\">" << endl;
   cout << "<tr>" << endl;
   cout << "<td>i</td>" << endl;
   cout << "<td>x<sub>i</sub></td>" << endl;
   cout << "<td>x<sub>i</sub><sup>2</sup></td>" << endl;
   cout << "<td>SUM(x<sub>i</sub>)</td>" << endl;
   cout << "<td>SUM(x<sub>i</sub><sup>2</sup>)</td>" << endl;
   cout << "<td>MIN(x<sub>i</sub>)</td>" << endl;
   cout << "<td>MAX(x<sub>i</sub>)</td>" << endl;
   cout << "</tr>" << endl;
   cout << "<tr>" << endl;
   cout << "<td>---</td>" << endl;
   cout << "<td>---</td>" << endl;
   cout << "<td>---</td>" << endl;
   cout << "<td>0.0</td>" << endl;
   cout << "<td>0.0</td>" << endl;
   cout << "<td>none</td>" << endl;
   cout << "<td>none</td>" << endl;
   cout << "</tr>" << endl;
}

//RECIEVES: Nothing
//TASK: Prints the closing table tag
//RETURNS: Nothing
void outputCloseTable()
{
   cout << "</table>" << endl;
}

//RECIEVES: Nothing
//TASK: Prints the footer of the program
//RETURNS: Nothing
void Footer(int size, float mean, float var, float sDev)
{
   cout << "<br><br><hr><br>" << endl;
   cout << "END OF PROGRAM OUTPUT" <<  "<br>" << endl;
   cout << "sample size is: " << size  <<  "<br>" << endl;
   cout << "sample mean is: " << mean <<  "<br>" << endl;
   cout << "sample variance is: " << var <<  "<br>" << endl;
   cout << "sample standard deviation is: " << sDev <<  "<br>" << endl;
   cout << "<br><hr>" << endl;
}

//RECIEVES: Nothing
//TASK: Prints the tags to close the html file
//RETURNS: Nothing
void closeDocument()
{
   cout << "</body>" << endl;
   cout << "</html>" << endl;
}

//RECIEVES: Nothing
//TASK: Loops through user input until the user types in "done" to console. If the user enters a number, the program will calculate the data and insert a new row into the table
//RETURNS: Nothing
void UserInput()
{
	int counter = 1;
	float var, mean, sDev,  numberInput, squared, sum, squaredSum, max = 0, min = 999999;
	string stringInput;

	while(true)
	{
		cerr << "Enter a number from 0-9:(enter 'done' when finished)" << endl;
		cin >> 	stringInput;
		if("done" == stringInput || "DONE" == stringInput)
		{
			break; //will stop the while loop
		}
		else
		{
			stringstream cast(stringInput);
			cast >> numberInput;
			max = MaxValue(numberInput, max);
			min = MinValue(numberInput, min);
			squared = Squaring(numberInput);
			squaredSum += squared;
			sum += numberInput;
			TableData(counter, numberInput, squared,  sum,  squaredSum,  max,  min);
			counter++;
		}
	}
	counter -= 1;
	mean = Mean(sum, counter);
	var = Variance(squaredSum, sum, counter);
	sDev = StandardDeviation(var);
	outputCloseTable();
	Footer(counter, mean, var, sDev);
	closeDocument();
}

//RECIEVES: the current number the user entered, the current max value
//TASK: test if the current number is greater than the current max, if it is then replace max with the current number
//RETURNS: max value
float MaxValue(float current, float max)
{
	if(current > max)
	{
		max = current;
	}
	return max;
}

//RECIEVES: the current number the user entered, the current min value
//TASK: test if the current number is less than the current min, if it is then replace min with the current number
//RETURNS: min value
float MinValue(float current, float min)
{
	if(current < min)
	{
		min = current;
	}
	return min;
}

//RECIEVES: the current number the user entered
//TASK: square the current number
//RETURNS: the current number squared
float Squaring(float current)
{
	current = pow(current,2);
	return current;
}

//RECIEVES: the number of numbers entered, current number entered by user, current number entered by user squared,
//          sum of all numbers entered, sqauredSum of all numbers entered, maximum number , minimum number
//TASK: print out all the data in a new row of the table
//RETURNS: nothing
void TableData(int counter, float current,float squared, float sum, float squaredSum, float max, float min)
{
	 cout << "<tr>" << endl;
	 cout << "<td>" << counter << "</td>" << endl;
	 cout << "<td>" << current << "</td>" << endl;
	 cout << "<td>" << squared << "</td>" << endl;
	 cout << "<td>" << sum << "</td>" << endl;
	 cout << "<td>" << squaredSum << "</td>" << endl;
	 cout << "<td>" << min << "</td>" << endl;
	 cout << "<td>" << max << "</td>" << endl;
	 cout << "</tr>" << endl;
}

//RECIEVES: the sum of all numbers entered, the number of digits entered
//TASK: calculate the mean
//RETURNS: the mean of all numbers entered by user
float Mean(float sum, int size)
{
	float mean;
	mean = sum/size;
	return mean;
}

//RECIEVES: the sum of all numbers squared, the sum of all numbers entered, the number of digits entered
//TASK: calculate the variance
//RETURNS: the variance
float Variance(float squaredSum, float sum, int size)
{
	float variance;
	variance = (squaredSum - ((sum*sum)/ size)) / (size - 1);
	return variance;
}

//RECIEVES: the variance
//TASK: calculate the standard deviation
//RETURNS: the standard deviation
float StandardDeviation(float variance)
{
	float sDev;
	sDev = sqrt (variance);
	return sDev;
}
