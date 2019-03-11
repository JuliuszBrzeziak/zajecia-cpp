#include <iostream>
#include <string>

class GradeBook
{
public:

    explicit GradeBook(std::string name) //co to explicit
        : courseName(name)
        {

        }
    void setCourseName(std::string name)
    {
        courseName = name;
    }

    std::string getCourseName() const
    {
        return courseName;
    }

    void displayMessage() const
    {
        std:: cout << "welcome"<< getCourseName() << "!" << std::endl;
    }

    private:
    std::string courseName;
};