#include <iostream>

using namespace std;

class Student
{
    public:

    Student():Student("","")
    {

    }
    Student(const string& firstName, const string& lastName): mFirstName(firstName), mLastName(lastName)
    {

    }
    // One way to compare objects is to define a function
    bool Equals(const Student& otherStudent)
    {
        return mFirstName == otherStudent.mFirstName
            && mLastName == otherStudent.mLastName;
    }
    
    // Another way is to overload the == operator
    bool operator==(const Student& otherStudent)
    {
        return mFirstName == otherStudent.mFirstName
            && mLastName == otherStudent.mLastName;
    }

    private:
    string mFirstName;
    string mLastName;
};

int main(int argc, const char * argv[])
{
    Student studentA("John", "Smith");
    Student studentB("Arthur", "Clark");
    Student studentC("John", "Smith");

    // Using function
    std::cout<<"Using function:"<<std::endl;
    if(studentA.Equals(studentC))
    {
        std::cout<<"Same students"<<std::endl;
    }
    else
    {
        std::cout<<"Different students"<<std::endl;
    }
    
    // Using operator
    std::cout<<"Using operator:"<<std::endl;
    if(studentA == studentC)
    {
        std::cout<<"Same students"<<std::endl;
    }
    else
    {
        std::cout<<"Different students"<<std::endl;
    }

    return 0;
}