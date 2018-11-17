/**
    GPA Calculator
    Purpose: Calculate GPA

    @author PZ
    @version 1.0
*/
#include <iostream>
#include "Class.h"
#include "GPACalculator.h"

using namespace std;

int main()
{
    cout << "GPA CALCULATOR" << endl << "======================" << endl;
    GPACalculator calculator(7, "grades.txt");
    cout << "CALCULATING GPA FOR: " << endl;
    calculator.printClasses();
    cout << "SEMESTER GPA: " << setprecision(3) << calculator.calculateSemesterGPA() << endl;
    cout << "WEIGHTED GPA: " << setprecision(3) << calculator.calculateWeightedGPA() << endl;

    return 0;
}
