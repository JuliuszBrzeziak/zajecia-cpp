#include <iostream>
#include "GradeBook.h"
using namespace std;

int main()
{
    GradeBook gradebook1("gradebook11");
    GradeBook gradebook2("gradeboook22");

    cout << "pierwszy grade book" << gradebook1.getCourseName()
    << "\ndrugi" << gradebook2.getCourseName() <<endl;
}