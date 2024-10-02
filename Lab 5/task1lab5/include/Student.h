#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using namespace std;

class Student
{
    public:
        Student();
        ~Student();
        void setName(string _name);
        void setDepartment(string dept);
        void setProgram(string prog);
        void setSection(string sec);
        void setAdmissionYear(int admission_year);
        void setAddress(string _address);
        string getName()const;
        string getDepartment() const;
        string getProgram() const;
        string getSection() const;
        int getAdmissionYear() const;
        string getAddress() const;
        float getGPA() const;
        void setQuiz1Marks(float q1);
        void setQuiz2Marks(float q2);
        void setQuiz3Marks(float q3);
        void setQuiz4Marks(float q4);
        void setMidMarks(float mid_marks);
        void setFinalsMarks(float finals_marks);
        void setAttendanceMarks(float attendance_marks);
        void calculateGPA();
        void generateID();
        string getID() const;

    private:
        string name;
        string department;
        string program;
        string section;
        string ID;
        int admissionYear;
        string address;
        float GPA;
        float quiz1;
        float quiz2;
        float quiz3;
        float quiz4;
        float mid;
        float finals;
        float attendance;
};

#endif // STUDENT_H
