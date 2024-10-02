#include <iostream>
#include "Student.h"
#include <string>

using namespace std;

Student::Student() { }

Student::~Student() { }

void Student::setName(string _name)
{
    name = _name;
}

void Student::setDepartment(string dept)
{
    department = dept;
}

void Student::setProgram(string prog)
{
    program = prog;
}

void Student::setSection(string sec)
{
    section = sec;
}

void Student::setAdmissionYear(int admission_year)
{
    admissionYear = admission_year;
}

void Student::setAddress(string _address)
{
    address = _address;
}

string Student::getName()const
{
    return name;
}

string Student::getDepartment() const
{
    return department;
}

string Student::getProgram() const
{
    return program;
}

string Student::getSection() const
{
    return section;
}

int Student::getAdmissionYear() const
{
    return admissionYear;
}

string Student::getAddress() const
{
    return address;
}

float Student::getGPA() const
{
    return GPA;
}

void Student::setQuiz1Marks(float q1)
{
    if(q1 <= 5.0)
        quiz1 = q1;
}
void Student::setQuiz2Marks(float q2)
{
    if(q2 <= 5.0)
        quiz2 = q2;
}
void Student::setQuiz3Marks(float q3)
{
    if(q3 <= 5.0)
        quiz3 = q3;
}
void Student::setQuiz4Marks(float q4)
{
    if(q4 <= 5.0)
        quiz4 = q4;
}
void Student::setMidMarks(float mid_marks)
{
    if(mid_marks <= 25.0)
        mid = mid_marks;
}
void Student::setFinalsMarks(float finals_marks)
{
    if(finals_marks <= 50.0)
        finals = finals_marks;
}
void Student::setAttendanceMarks(float attendance_marks)
{
    if(attendance_marks <= 10.0)
        attendance = attendance_marks;
}

void Student::calculateGPA()
{
    float totalQuizMarks;

    if(quiz1 < quiz2 && quiz1 < quiz3 && quiz1 < quiz4)
    {
        totalQuizMarks = quiz2 + quiz3 + quiz4;
    }
    else if(quiz2 < quiz1 && quiz2 < quiz3 && quiz2 < quiz4)
    {
        totalQuizMarks = quiz1 + quiz3 + quiz4;
    }
    else if(quiz3 < quiz2 && quiz3 < quiz1 && quiz3 < quiz4)
    {
        totalQuizMarks = quiz1 + quiz2 + quiz4;
    }
    else
    {
        totalQuizMarks = quiz1 + quiz2 + quiz3;
    }

    float total = totalQuizMarks + attendance + mid + finals;

    if(total >= 80)
        GPA = 4.00;
    else if(total >= 75)
        GPA = 3.75;
    else if(total >= 70)
        GPA = 3.5;
    else if(total >= 60)
        GPA = 3.0;
    else if(total >= 50)
        GPA = 2.5;
    else if(total >= 40)
        GPA = 2.0;
    else
        GPA = 0.0;
}

void Student::generateID()
{
    static int cse1 = 0;
    static int cse2 = 0;
    static int swe = 0;

    int y = admissionYear % 100;
    ID = to_string(y);
    ID += "00";
    if(department == "CSE")
    {
        if(program == "CSE")
        {
            if(section == "1")
            {
                ID += "411";
                cse1++;
                if(cse1 < 10)
                {
                    ID += "0";
                    ID += to_string(cse1);
                }
                else
                    ID += to_string(cse1);
            }
            else
            {
                ID += "412";
                cse2++;
                if(cse2 < 10)
                {
                    ID += "0";
                    ID += to_string(cse2);
                }
                else
                    ID += to_string(cse2);
            }
        }
        else
        {
            ID += "421";
            swe++;
            if(swe < 10)
            {
                ID += "0";
                ID += to_string(swe);
            }
            else
                ID += to_string(swe);
        }
    }
}

string Student::getID() const
{
    return ID;
}
