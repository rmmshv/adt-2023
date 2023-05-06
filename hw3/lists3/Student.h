// Specification file for the Student class
// Written by: A. Student
// Reviewed & Modified by: Rimma Esheva
// IDE: VS Code

#ifndef STUDENT_H
#define STUDENT_H

//using namespace std;  //<==== This statement
// in a header file of a complex project could create
// namespace management problems for the entire project
// (such as name collisions).
// Do not write namespace using statements at the top level in a header file!

using std::string;

class Student
{
private:
/* Write your code here: gpa - a double, name - a string */
    double gpa;
    std::string name;

    
public:
    /* Write your code here: default and overloaded constructors  */
    Student() {
        gpa = -1;
        name = "";
    };
    Student(double GPA, std::string NAME) {
        gpa = GPA;
        name = NAME;
    }

    // Setters and getters
    /* Write your code here: a setter and a getter for each data member of the class  */
    void setGpa(double GPA) { gpa = GPA; }
    void setName(str::string NAME) { name = NAME; }

    double getGpa() { return gpa; }
    std::string getName() { return name; }
};
#endif
