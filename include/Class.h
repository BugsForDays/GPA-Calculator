#ifndef CLASS_H
#define CLASS_H
#include <string>

class GPAClass
{
    public:
        GPAClass(std::string name = "null" , std::string grade = "n+" , float creds = 1.5);
        std::string className;
        std::string letterGrade;
        float credits;
};

#endif // CLASS_H
