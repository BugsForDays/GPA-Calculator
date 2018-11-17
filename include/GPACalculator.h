#ifndef GPACALCULATOR_H
#define GPACALCULATOR_H
#include "Class.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class GPACalculator
{
    public:
        GPACalculator(int numClasses, std::string fromFile = "");
        float calculateSemesterGPA();
        float calculateWeightedGPA();
        void printClasses();

    private:
        void getClassDataFromFile(std::string filename);
        void getClassData();
        float gradePointEquivalentResolver(std::string letterCheck);
        int numberofClasses;
        GPAClass classes[8];
};

#endif // GPACALCULATOR_H
