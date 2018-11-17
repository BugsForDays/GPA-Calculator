/**
    GPA Calculator
    GPACalculator.cpp
    Purpose: Define functions for GPACalculator class

    @author PZ
    @version 1.0
*/
#include "GPACalculator.h"

using namespace std;

/** @brief initializes a GPACalculator object, automatically stores grade data based on second parameter
 *
 * @param numClasses The number of class periods to calculate GPA for
 * @param fromFile (optional) File name to read grade data from
 * @return None
 *
 */
GPACalculator::GPACalculator(int numClasses, string fromFile)
{
    numberofClasses = numClasses;
    if (!fromFile.empty()) {
        GPACalculator::getClassDataFromFile(fromFile);
    } else {
        GPACalculator::getClassData();
    }
}

/** @brief reads and stores grade data
 *
 * @param filename File to read grade data from
 * @return None
 *
 */
void GPACalculator::getClassDataFromFile(string filename)
{
    ifstream gradesFile(filename);
    if (!gradesFile){
        cout << "File error: cannot open" << endl;
    } else {
        string fileInputs[22];
        int counter = 0;
        while(gradesFile){
            string line;
            gradesFile >> line;
            fileInputs[counter] = line;
            counter++;
        }
        int pointer = 0;
        for (int x = 0; x < numberofClasses; x++) {
            string name = fileInputs[pointer];
            string grade = fileInputs[pointer+1];
            float cred = stof(fileInputs[pointer+2]);
            GPAClass temp(name, grade, cred);
            classes[x] = temp;
            pointer += 3;
        }
    }
}

/** @brief prompts user to enter grade data manually and stores it
 *
 * @return None
 *
 */

void GPACalculator::getClassData()
{
    cout << "Input your classes:" << endl;
    for (int x = 0; x < numberofClasses; x++) {
        cout << "=================" << endl;
        cout << "Class " << x+1 << endl;
        cout << "Enter the name of the class: ";
        string name;
        cin >> name;
        cout << "Enter letter grade(a+, b-, etc): ";
        string grade;
        cin >> grade;
        cout << "Enter credits: ";
        float cred;
        cin >> cred;
        GPAClass temp(name, grade, cred);
        classes[x] = temp;
    }
}

/** @brief calculates semester(unweighted GPA) from grade data
 *
 * @return calculated unweighted GPA.
 *
 */

float GPACalculator::calculateSemesterGPA()
{
    float gradePoints = 0;
    float totalCredits = 0;
    for(int x = 0; x < numberofClasses; x++) {
        string letterCheck = classes[x].letterGrade;
        float gradePointEquivalent = GPACalculator::gradePointEquivalentResolver(letterCheck);
        gradePoints += gradePointEquivalent * classes[x].credits;
        totalCredits += classes[x].credits;
        }
    return gradePoints/totalCredits;
}

/** @brief calculates weighted GPA from grade data
 *
 * @return calculated weighted GPA
 *
 */

float GPACalculator::calculateWeightedGPA()
{
    float gradePoints = 0;
    float totalCredits = 0;
    for(int x = 0; x < numberofClasses; x++) {
        string letterCheck = classes[x].letterGrade;
        float gradePointEquivalent = GPACalculator::gradePointEquivalentResolver(letterCheck);
        if(classes[x].className.find("ap") != string::npos) gradePointEquivalent += 1;
        gradePoints += gradePointEquivalent * classes[x].credits;
        totalCredits += classes[x].credits;
        }
    return gradePoints/totalCredits;
}

/** @brief resolves floating point gradepointequivalent from letter grade
 *
 * @param letterCheck letter grade to check
 * @return grade point equivalent
 *
 */

float GPACalculator::gradePointEquivalentResolver(string letterCheck)
{
    float gradePointEquivalent;
    if((letterCheck== "a+") || (letterCheck== "a")) gradePointEquivalent = 4.0;
    else if(letterCheck == "a-") gradePointEquivalent = 3.67;
    else if(letterCheck == "b+") gradePointEquivalent = 3.33;
    else if(letterCheck == "b") gradePointEquivalent = 3.0;
    else if(letterCheck == "b-") gradePointEquivalent = 2.67;
    else if(letterCheck == "c+") gradePointEquivalent = 2.33;
    else if(letterCheck == "c") gradePointEquivalent = 2.0;
    else if(letterCheck == "c-") gradePointEquivalent = 1.67;
    else if(letterCheck == "d+") gradePointEquivalent = 1.33;
    else if(letterCheck == "d") gradePointEquivalent = 1.0;
    else gradePointEquivalent = 0.0;
    return gradePointEquivalent;
}

/** @brief prints class data to console(name, grade, credits)
 *
 *
 */

void GPACalculator::printClasses()
{
    cout << string(25,'-') << endl << "|PR|  CLASS  |GRADE|CRED|" << endl;
    for (int x = 0; x < numberofClasses; x++) {
        cout << '|' << x+1 << ".  " << classes[x].className << string(10-classes[x].className.length(), ' ') << classes[x].letterGrade
        << string(7-classes[x].letterGrade.length(), ' ') << classes[x].credits << " |" << endl << string(25,'-') << endl;
    }
}
