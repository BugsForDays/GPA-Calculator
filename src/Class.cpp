/**
    GPA Class
    Class.cpp
    Purpose: Class definition of a real life class

    @author PZ
    @version 1.0
*/
#include "Class.h"
#include <string>

using namespace std;

GPAClass::GPAClass(std::string name, std::string grade, float creds)
{
    className = name;
    letterGrade = grade;
    credits = creds;
}
