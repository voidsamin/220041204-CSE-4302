#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

void EditInformationByKeyboard(Student s[], int index)
{
    cout << "Enter student name: ";
    string name;
    getline(cin, name);
    s[index].setName(name);

    cout << "Enter student department: ";
    string dept;
    getline(cin, dept);
    s[index].setDepartment(dept);

    cout << "Enter student program: ";
    string prog;
    getline(cin, prog);
    s[index].setProgram(prog);

    cout << "Enter student section: ";
    string sec;
    getline(cin, sec);
    s[index].setSection(sec);

    cout << "Enter student admission year: ";
    int year;
    cin >> year;
    cin.ignore();
    s[index].setAdmissionYear(year);

    cout << "Enter student address: ";
    string address;
    getline(cin, address);
    s[index].setAddress(address);

    s[index].generateID();
}

void generateInformationRandom(Student s[], int index)
{

    int q1 = rand() % 6;
    int q2 = rand() % 6;
    int q3 = rand() % 6;
    int q4 = rand() % 6;

    int mid = rand() % 26;
    int finals = rand() % 51;
    int att = rand() % 11;

    s[index].setQuiz1Marks((float)q1);
    s[index].setQuiz2Marks((float)q2);
    s[index].setQuiz3Marks((float)q3);
    s[index].setQuiz4Marks((float)q4);

    s[index].setAttendanceMarks((float)att);
    s[index].setMidMarks((float)mid);
    s[index].setFinalsMarks((float)finals);

    s[index].calculateGPA();
}

void ShowAllAlphabetically(Student s[])
{
    for(int i = 0; i < 2; i++)
    {
        cout << "Student Name: " << s[i].getName() << " Student ID: " << s[i].getID() << " Student GPA: " << s[i].getGPA() << endl;
    }
}

int main()
{
    Student s[100];

    for(int i = 0; i < 2; i++)
    {
        EditInformationByKeyboard(s, i);
        generateInformationRandom(s, i);
    }

    ShowAllAlphabetically(s);
}
