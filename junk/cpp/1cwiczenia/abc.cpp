#include<iostream>
#include<string>
using namespace std;

class GradeBook
{
    public:

    void setCourseName(string name)
    {
        courseName = name;
    }

    string getCourseName() const
    {
        return courseName;
    }

    void displayMessage() const //po co jest ten const?
    {
        cout << "welcome to the Grade Book!" << getCourseName() << "!" << endl;
    }

private:
string courseName;

};

int main()
{
    string nameOfCourse;

    GradeBook myGradeBook;

    cout << "initial course name is" << myGradeBook.getCourseName() << endl;
    cout<< "\n enter blah blah blah"<<endl;
    getline(cin,nameOfCourse); //co oznacza cin, co to getline
    cout << endl;
    //myGradeBook.displayMessage( nameOfCourse );
    cout << "one more time" << endl;
    myGradeBook.setCourseName(nameOfCourse);
    cout << endl;
    myGradeBook.displayMessage( );
}