#include <iostream>

using namespace std;

class Student
{
    int Checker ;
    int stdID;
    int numCourses;
    int *courseGrades;

    string Name;
    string *courseCodes;

    float gpa;

public:

    // Constructor 
    Student()
    {
        Checker=0;
        stdID = 0;
        numCourses = 0;
        Name = "";

        courseCodes = NULL;
    }
    
    //Getters and Setters 
    int getStdID()
    {
        return stdID;
    }

    int getNumCourses()
    {
        return numCourses;
    }

    int getCourseGrade(int i)
    {
        return courseGrades[i];
    }

    string getName()
    {
        return Name;
    }

    string getCourseCode(int i)
    {
        return courseCodes[i];
    }

    float getGPA()
    {
        return gpa;
    }

    void setStdID(int id)
    {
        this->stdID = id;
    }

    void setName(string firstName)
    {
        this->Name = firstName;
    }

    // Setting the Grade after finding the appropriate Course by comparing 
    void setCourseGrade(string courseCode, int grade)
    {
        for (int i = 0; i < this->numCourses; i++)
        {
            if (this->courseCodes[i] == courseCode)
            {
                courseGrades[i] = grade;
                break;
            }
        }
    }

    // Adding a Course after checking If the Course Added doesnot exceed the 
    // number of courses 
    void addCourse(string courseCode, int grade)
    {
        this->Checker++;
        if (this->Checker <= this->numCourses)
        {
            this->courseCodes[numCourses] = courseCode;
            this->courseGrades[numCourses] = grade;
        }
    }
    
    //Suming all the Grades and dividing them by the total number of courses  
    void calcGPA()
    {
        int sum = 0;

        for (int i = 0; i < this->numCourses; i++)
        {
            sum += this->courseGrades[i];
        }

        this->gpa = sum / numCourses;
    }
};

// !!  GLOBAL FUNCTIONS

Student getStudentAt(Student students[], int index)
{
    return students[index];
}

// Adding the total GPA of the class and dividing it by the total number of students 
float calcClassGPA(Student students[], int numStudents)
{
    float TGpa = 0;
    for (int i = 0; i < numStudents; i++)
    {
        float temp = students[i].getGPA();
        TGpa += temp;
    }

    return TGpa / float(numStudents);
}

// Loping through all the students and finding the Largest GPA and returning it 
float getMaxGPA(Student students[], int numStudents)
{
    float MGpa = students[0].getGPA();
    for (int i = 1; i < numStudents; i++)
    {
        float temp = students[i].getGPA();
        if (temp > MGpa)
        {
            MGpa = temp;
        }
    }

    return MGpa;
}
// Loping through all the students and finding the smallest GPA and returning it 
int getMinGPA(Student students[], int numStudents)
{
    int MiGpa = 1000000;
    for (int i = 1; i < numStudents; i++)
    {
        float temp = students[i].getGPA();
        if (temp < MiGpa)
        {
            MiGpa = temp;
        }
    }

    return MiGpa;
}

// Printing Individual Student Record 
void printStudentRecord(Student student)
{
    cout << "The Name  of the student is " << student.getName() << " with Id " << student.getStdID() << " and registered in " << student.getNumCourses() << " courses " << endl;

    int n = student.getNumCourses();

    cout << "\nHis Grades are \n";

    for (int i = 0; i < n; i++)
    {
        cout << "Course Code : " << student.getCourseCode(i) << "Grade :\t" << student.getCourseGrade(i) << endl;
    }
}

// Printing information of all the students present in the class 
void printAllStudentRecords(Student students[], int numStudents)
{
    for (int i = 0; i < numStudents; i++)
    {
        cout << "The Name  of the student is " << students[i].getName() << " with Id " << students[i].getStdID() << " registered in " << students[i].getNumCourses() << " courses " << endl;

        int n = students[i].getNumCourses();

        cout << "\nHis Grades are \n";

        for (int j = 0; j < n; j++)
        {
            cout << "Course Code : " << students[i].getCourseCode(j) << "Grade :\t" << students[i].getCourseGrade(j) << endl;
        }
    }
}

int main()
{

    return 0;
}